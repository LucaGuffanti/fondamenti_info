#include <stdio.h>

/*input-output*/
#define READ 10
#define WRITE 11

/*caricamento-memorizzazione*/
#define LOAD 20
#define STORE 21

/*aritmetica*/
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33

/*trasferimento del controllo*/
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43


#define STOPINSERT -99999

/*uso della memoria e registri*/
#define ACCUMULATORE 100


void start();
void saveInstructions(int [], int, int *);
void programExecution(int [], int);
void dump(int [], int, int, int, int, int, int);

int main(){

    int memory[ACCUMULATORE];
    int dimAcc, i;


    start();
    saveInstructions(memory, ACCUMULATORE, &dimAcc);
    programExecution(memory, ACCUMULATORE);



    return 0;
}

void start(){

    printf("Welcome to Simpletron\n");
    printf("    Please enter program one instruction\n");
    printf("    (or data word) at a time. I will type the\n");
    printf("    location mark and a question mark (?).\n");
    printf("    You type the word for that location.\n");
    printf("    Type the sentinel -99999 to stop entering\n");
    printf("    your program.\n\n");

}

void saveInstructions(int mem[], int dim, int *effectiveDim){
    int i, exit, instruction;

    for(i = 0; i < dim; i++){
        mem[i] = 0;
    }

    for(i = 0, exit = 0; i < dim && !exit; i++){
 
        printf("%3d ? ", i);
        scanf("%d", (mem + i));

        if(*(mem + i) == STOPINSERT){
            exit = 1;
        }
    }

    *effectiveDim = i;

    printf("    Program Loading Completed\n");
}

void programExecution(int mem[], int dim){
    
    int accumulator;
    int instructionCounter;
    int operationCode;
    int operand;
    int instructionRegister;
    int i;

    accumulator = +0000;
    instructionCounter = 00;
    instructionRegister = +0000;
    operationCode = 00;
    operand = 00;

    printf("    Program execution begins\n");

    for(; instructionCounter < dim; instructionCounter++){
        
        instructionRegister = mem[instructionCounter];
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;

        switch (operationCode)
        {
        case READ:
            printf("?   ");
            scanf("%d", &mem[operand]);
            break;
        case WRITE:
            break;
        case LOAD:
            accumulator = mem[operand];
            break;
        case STORE:
            break;
        case ADD:
            if(!(accumulator + mem[operand] < 9999)){
                accumulator += mem[operand];
                printf("Overflow. Process terminated\n");
            }
            break;
        case SUBTRACT:
            if(!(accumulator - mem[operand] > -9999)){
                accumulator -= mem[operand];
                printf("Underflow. Process terminated\n");
            }
            break;
        case DIVIDE:
            if(mem[operand] == 0){
                printf("Division by zero is impossible.\n");
            }
            else{
                accumulator /= mem[operand];
            }
            break;
        case MULTIPLY:
            accumulator *= mem[operand];
            break;
        case BRANCH:
            instructionCounter = operand;
            break;
        case BRANCHNEG:
            break;
        case BRANCHZERO:
            if(accumulator == 0){
                instructionCounter = operand;
            }
            break;
        case HALT:
            printf("");
            break;
        default:
            break;
        }
    }

    dump(mem, dim, accumulator, instructionRegister, operationCode, operand, instructionCounter);

}

void dump(int mem[], int dim, int accumulator, int instructionRegister, int operationCode, int operand, int instructionCounter){

    int i;

    printf("REGISTERS:\n");
    printf("accumulator             %6d\n", accumulator);
    printf("instructionCounter      %6d\n", instructionCounter);
    printf("instructionRegister     %6d\n", instructionRegister);
    printf("operationCode           %6d\n", operationCode);
    printf("operand                 %6d\n", operand);

    printf("MEMORY:\n");
    for(i = 0; i < dim; i++){
        if(i % 9 != 0){
            printf("%4d ", mem[i]);
        }
        else{
            printf("%4d\n", mem[i]);
        }
    }


}