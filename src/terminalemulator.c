#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
unsigned int  code[4];
void enterbin(void);
void  intro(void);
void halt(void);
void cpu_state(void);
int main(){
intro();
enterbin();
cpu_state();
return 0;
}
void enterbin(){
bool status;
int g=1;
unsigned char check_user_rom;
printf("Before Proceeding , Are you using 4x4 ROM setup? y/n\n");
scanf("%c",&check_user_rom);
status =(check_user_rom =='y')?true:false;
if(status){

for(int i=0;i<4;i++){
printf(" line no %d  in decimal(0-15)\n",g);
scanf("%d",&code[i]);
if((code[i]<0) || (code[i]>15)){
printf(" Yikes ! out of memory Region\n");
break;
}
g++;
if(g==4)
g=0;
}
}
else if(!status){
printf("Sorry not supported yet will be included soon\n");
}
}
void intro(){
printf("\n=============================******======== 1 BIT CPU EMULATOR ========******====================================\n\n");
}
void cpu_state(){
uint8_t REG[2]={0};
bool HALT =false;
uint8_t PC=0;
while(!HALT && PC<4){
bool H=code[PC]&(1<<0);
bool I =code[PC]&(1<<1);
bool S =code[PC]&(1<<2);
bool D =code[PC]&(1<<3);
uint8_t data = (I == 0) ? REG[S] : S;
REG[D] = data;
 printf("PC=%d | Instr=%d | A=[%s] B=[%s]\n", PC, code[PC],
       REG[0] ? "1" : "⚪", REG[1] ? "0" : "⚪");


        if (H) {
            HALT = true;
            halt();
        } else {
            PC++;
        }
}
}

void halt(void){
printf(" CPU EXECUTION HALTED\n");
}
