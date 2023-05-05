#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    const char* name;
    int num;
} reg;

typedef struct
{
    const char* name;
    void (*f)(const char*, const char*, const char*);
} command;

reg registers[] =
{
  {"AX", 0}, {"BX", 0}, {"CX", 0}, {"DX", 0}, {"EX", 0},
  {"FX", 0}, {"GX", 0}, {"HX", 0}, {"IX", 0}, {"JX", 0},
  {"KX", 0}, {"LX", 0}, {"MX", 0}, {"NX", 0}, {"OX", 0},
  {"PX", 0}, {"QX", 0}, {"RX", 0}, {"SX", 0}, {"TX", 0},
  {"UX", 0}, {"VX", 0}, {"WX", 0}, {"XX", 0}, {"YX", 0},
  {"ZX", 0}
};

int mapping(const char* str)
{
    return str[0] - 'A';
}

void IN(const char* reg, int number)
{
    registers[mapping(reg)].num = number;
}

void OUT(const char* reg)
{
    printf("%d\n", registers[mapping(reg)].num);
}

void MOV(const char* reg1, const char* reg2)
{
    registers[mapping(reg1)].num = registers[mapping(reg2)].num;
}

void XCHG(const char* reg1, const char* reg2)
{
    int temp = registers[mapping(reg1)].num;
    registers[mapping(reg1)].num = registers[mapping(reg2)].num;
    registers[mapping(reg2)].num = temp;
}

void ADD(const char* reg1, const char* reg2, const char* reg3);
void SUB(const char* reg1, const char* reg2, const char* reg3);
void MUL(const char* reg1, const char* reg2, const char* reg3);
void DIV(const char* reg1, const char* reg2, const char* reg3);
void MOD(const char* reg1, const char* reg2, const char* reg3);
void AND(const char* reg1, const char* reg2, const char* reg3);
void OR( const char* reg1, const char* reg2, const char* reg3);
void XOR(const char* reg1, const char* reg2, const char* reg3);
void Interpreter(char* line);

command commands[] =
{
    {"ADD", ADD}, {"SUB", SUB}, {"MUL", MUL}, {"DIV", DIV},
    {"MOD", MOD}, {"AND", AND}, {"OR" , OR }, {"XOR", XOR}
};

const char* cmds[] = {"ADD", "SUB", "MUL", "DIV", "MOD", "AND", "OR", "XOR"};

int mapping_cmd(const char* str)
{
    for (int i = 0; i < 8; i++) {
        if (strcmp(str, cmds[i]) == 0) return i;
    }
    return -1;
}

int main()
{
    char cmd[120] = {0};
    while (gets(cmd)) {
        Interpreter(cmd);
    }
    return 0;
}

void ADD(const char* reg1, const char* reg2, const char* reg3)
{
    if (strcmp(reg3, "")) registers[mapping(reg1)].num = registers[mapping(reg2)].num + registers[mapping(reg3)].num;
    else registers[mapping(reg1)].num += registers[mapping(reg2)].num;
}

void SUB(const char* reg1, const char* reg2, const char* reg3)
{
    if (strcmp(reg3, "")) registers[mapping(reg1)].num = registers[mapping(reg2)].num - registers[mapping(reg3)].num;
    else registers[mapping(reg1)].num -= registers[mapping(reg2)].num;
}

void MUL(const char* reg1, const char* reg2, const char* reg3)
{
   if (strcmp(reg3, "")) registers[mapping(reg1)].num = registers[mapping(reg2)].num * registers[mapping(reg3)].num;
    else registers[mapping(reg1)].num *= registers[mapping(reg2)].num;
}

void DIV(const char* reg1, const char* reg2, const char* reg3)
{
    if (strcmp(reg3, "")) registers[mapping(reg1)].num = registers[mapping(reg2)].num / registers[mapping(reg3)].num;
    else registers[mapping(reg1)].num /= registers[mapping(reg2)].num;
}

void MOD(const char* reg1, const char* reg2, const char* reg3)
{
    if (strcmp(reg3, "")) registers[mapping(reg1)].num = registers[mapping(reg2)].num % registers[mapping(reg3)].num;
    else registers[mapping(reg1)].num %= registers[mapping(reg2)].num;
}

void AND(const char* reg1, const char* reg2, const char* reg3)
{
    if (strcmp(reg3, "")) registers[mapping(reg1)].num = registers[mapping(reg2)].num & registers[mapping(reg3)].num;
    else registers[mapping(reg1)].num &= registers[mapping(reg2)].num;
}

void OR(const char* reg1, const char* reg2, const char* reg3)
{
    if (strcmp(reg3, "")) registers[mapping(reg1)].num = registers[mapping(reg2)].num | registers[mapping(reg3)].num;
    else registers[mapping(reg1)].num |= registers[mapping(reg2)].num;
}

void XOR(const char* reg1, const char* reg2, const char* reg3)
{
    if (strcmp(reg3, "")) registers[mapping(reg1)].num = registers[mapping(reg2)].num ^ registers[mapping(reg3)].num;
    else registers[mapping(reg1)].num ^= registers[mapping(reg2)].num;
}

void Interpreter(char* line)
{
    int len = strlen(line);
    for (int i = 0; i < len; i++) {
        if (line[i] == ',') line[i] = ' ';
    }
    // int regs_beg = find_first_space(line);
    char cmd[20] = {0};
    strcpy(cmd, strtok(line, " "));

    if (strcmp(cmd, "OUT") != 0) {
        if (strcmp(cmd, "IN") == 0) {
            char reg1[20] = {0};
            strcpy(reg1, strtok(NULL, " "));
            int num = atoi(strtok(NULL, " "));
            IN(reg1, num);
        }
        else if (strcmp(cmd, "MOV") == 0) {
            char reg1[20] = {0}, reg2[20] = {0};
            strcpy(reg1, strtok(NULL, " "));
            strcpy(reg2, strtok(NULL, " "));
            MOV(reg1, reg2);
        }
        else if (strcmp(cmd, "XCHG") == 0) {
            char reg1[20] = {0}, reg2[20] = {0};
            strcpy(reg1, strtok(NULL, " "));
            strcpy(reg2, strtok(NULL, " "));
            XCHG(reg1, reg2);
        }
        else {
            char* temp = NULL;
            char regs[5][20] = {{0}};
            int cnt = 0;
            while (temp = strtok(NULL, " ")) {
                strcpy(regs[cnt++], temp);
            }
            void (*fT)(const char*, const char*, const char*) = commands[mapping_cmd(cmd)].f;
            fT(regs[0], regs[1], regs[2]);
        }
    }
    else {
        printf("%d\n", registers[mapping(strtok(NULL, " "))].num);
    }
}

