// Barbara Este Fernandez - 31937039

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define RESERVED_WORD "RESERVED_WORD"
#define IDENTIFIER "IDENTIFIER"
#define BOOLEAN "BOOLEAN"
#define OPERATOR "OPERATOR"
#define DELIMITER "DELIMITER"


FILE *saida;


void writeLexicalItem(int initial, int final, char *string, char* type) {
	int i = initial;
	fputc('<', saida);
	fputs(type, saida);
	fputs(", ", saida);
	while(i < final) {
		printf("%c", string[i]);
		fputc(string[i], saida);
		i++;
	}
	fputs(">\n", saida);
}

char * scanner(char string[], int *pointer) {
	int initial_pointer = *pointer, tam = 0;
	printf("\n\nEntered scanner");
	goto q0;

	q0: //Estado inicial
		printf("\nEntered q0 state");
		
		if(string[*pointer] == 't') goto q1;
		if(string[*pointer] == 'f') goto q2;
		if(string[*pointer] == 'p') goto q3;
		if(string[*pointer] == 's') goto q14;
		if(string[*pointer] == 'b') goto q17;
		if(string[*pointer] == 'i') goto q22;
		if(string[*pointer] == 'e') goto q26;
		if(string[*pointer] == 'r') goto q40;
		if(string[*pointer] == '_') goto q61;
		if(string[*pointer] == '+') goto q70;
		if(string[*pointer] == '-') goto q72;
		if(string[*pointer] == '*') goto q75;
		if(string[*pointer] == '<') goto q77;
		if(string[*pointer] == '>') goto q79;
		if(string[*pointer] == '=') goto q85;
		if(string[*pointer] == '!') goto q87;
		if(string[*pointer] == '(') goto q92;
		if(string[*pointer] == ')') goto q94;
		if(string[*pointer] == ',') goto q96;
		if(string[*pointer] == ';') goto q98;
		if(string[*pointer] == '.') goto q100;
		else goto final;
		
	q1:
		printf("\nEntered q1 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q01;
		else goto final;
		
	q2:
		printf("\nEntered q2 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q34;
		if(string[*pointer] == 'i') goto q35;
		else goto final;

	q3:
		printf("\nEntered q3 state");
		(*pointer)++;
		if(string[*pointer] == 'r') goto q4;
		else goto final;
		
	q4:
		printf("\nEntered q4 state");
		(*pointer)++;
		if(string[*pointer] == 'o') goto q5;
		else goto final;
		
	q5:
		printf("\nEntered q5 state");
		(*pointer)++;
		if(string[*pointer] == 'c') goto q47;
		if(string[*pointer] == 'g') goto q6;
		else goto final;
		
	q6:
		printf("\nEntered q6 state");
		(*pointer)++;
		if(string[*pointer] == 'r') goto q7;
		else goto final;
		
	q7:
		printf("\nEntered q7 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q60;
		else goto final;

	q8:
		printf("\nEntered q8 state");
		(*pointer)++;
		if(string[*pointer] == 'a') goto q9;
		else goto final;
		
	q9:
		printf("\nEntered q9 state");
		(*pointer)++;
		if(string[*pointer] == 'o') goto q10;
		else goto final;
		
	q10:
		printf("\nEntered q10 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q11;
		else goto final;

	q11: //Palavra reservada "senao" encontrada'
		printf("\nEntered q11 state. Found reserved word \'senao\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, RESERVED_WORD);

	q12:
		printf("\nEntered q12 state");
		(*pointer)++;
		if(string[*pointer] == 't') goto q13;
		else goto final;
		
	q13:
		printf("\nEntered q13 state");
		(*pointer)++;
		if(string[*pointer] == 'a') goto q49;
		else goto final;
		
	q14:
		printf("\nEntered q14 state");
		(*pointer)++;
		if(string[*pointer] == 'e') goto q15;
		else goto final;
		
	q15:
		printf("\nEntered q15 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q16;
		if(string[*pointer] == 'n') goto q8;
		else goto final;
		
	q16: //Palavra reservada "se" encontrada
		printf("\nEntered q16 state. Found reserved word \'se\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;
		
	q17:
		printf("\nEntered q17 state");
		(*pointer)++;
		if(string[*pointer] == 'o') goto q18;
		else goto final;
		
	q18:
		printf("\nEntered q18 state");
		(*pointer)++;
		if(string[*pointer] == 'o') goto q19;
		else goto final;
		
	q19:
		printf("\nEntered q19 state");
		(*pointer)++;
		if(string[*pointer] == 'l') goto q20;
		else goto final;
		
	q20:
		printf("\nEntered q20 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q21;
		else goto final;
		
	q21: //Palavra reservada "bool" encontrada
		printf("\nEntered q21 state. Found reserved word \'bool\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;
		
	q22:
		printf("\nEntered q22 state");
		(*pointer)++;
		if(string[*pointer] == 'n') goto q23;
		else goto final;
		
	q23:
		printf("\nEntered q23 state");
		(*pointer)++;
		if(string[*pointer] == 't') goto q24;
		else goto final;
		
	q24:
		printf("\nEntered q24 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q25;
		else goto final;
		
	q25: //Palavra reservada "int" encontrada
		printf("\nEntered q25 state. Found reserved word \'int\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;
		
	q26:
		printf("\nEntered q26 state");
		(*pointer)++;
		if(string[*pointer] == 's') goto q27;
		if(string[*pointer] == 'n') goto q12;
		else goto final;
		
	q27:
		printf("\nEntered q27 state");
		(*pointer)++;
		if(string[*pointer] == 'c') goto q28;
		else goto final;
		
	q28:
		printf("\nEntered q28 state");
		(*pointer)++;
		if(string[*pointer] == 'r') goto q29;
		else goto q29;
		
	q29:
		printf("\nEntered q29 state");
		(*pointer)++;
		if(string[*pointer] == 'e') goto q30;
		else goto final;
		
	q30:
		printf("\nEntered q30 state");
		(*pointer)++;
		if(string[*pointer] == 'v') goto q31;
		else goto final;
		
	q31:
		printf("\nEntered q31 state");
		(*pointer)++;
		if(string[*pointer] == 'a') goto q32;
		else goto final;
		
	q32:
		printf("\nEntered q32 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q33;
		else goto final;
		
	q33: //Palava reservada "escreva" encontrada.
		printf("\nEntered q33 state. Found reserved word \'escreva\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

 	q34: //Booleano t encontrado
		printf("\nEntered q34 state. Found f boolean value.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, BOOLEAN);
		(*pointer)++;
		goto final;
		
	q35:
		printf("\nEntered q35 state");
		(*pointer)++;
		if(string[*pointer] == 'm') goto q36;
		else goto final;
		
	q36:
		printf("\nEntered q36 state");
		(*pointer)++;
		if(string[*pointer] == 's') goto q37;
		else goto final;
		
	q37:
		printf("\nEntered q37 state");
		(*pointer)++;
		if(string[*pointer] == 'e') goto q38;
		else goto final;
	
	q38:
		printf("\nEntered q38 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q39;
		else goto final;
		
	q39: //Palavra reservada "fimse" encontrada
		printf("\nEntered q39 state. Found reserved word \'fimse\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;
		
	q40:
		printf("\nEntered q40 state");
		(*pointer)++;
		if(string[*pointer] == 'e') goto q41;
		else goto final;
		
	q41:
		printf("\nEntered q41 state");
		(*pointer)++;
		if(string[*pointer] == 'p') goto q42;
		else goto final;
		
	q42:
		printf("\nEntered q42 state");
		(*pointer)++;
		if(string[*pointer] == 'i') goto q43;
		else goto final;
		
	q43:
		printf("\nEntered q43 state");
		(*pointer)++;
		if(string[*pointer] == 't') goto q44;
		else goto final;
		
	q44:
		printf("\nEntered q44 state");
		(*pointer)++;
		if(string[*pointer] == 'a') goto q45;
		else goto final;
		
	q45:
		printf("\nEntered q45 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q46;
		else goto final;
		
	q46: //Palava reservada "repita" encontrada
		printf("\nEntered q46 state. Found reserved word \'repita\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;
		
	q47:
		printf("\nEntered q47 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q48;
		else goto final;
		
	q48: //Palavra reservada "proc" encontrada
		printf("\nEntered q48 state. Found reserved word \'proc\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q49:
		printf("\nEntered q49 state");
		(*pointer)++;
		if(string[*pointer] == 'o') goto q50;
		else goto final;
		
	q50:
		printf("\nEntered q50 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q51;
		
	q51: //Palava reservada "entao" encontrada
		printf("\nEntered q51 state. Found reserved word \'entao\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q01: //Booleano t encontrado
		printf("\nEntered q01 state. Found t boolean value.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, BOOLEAN);
		(*pointer)++;
		goto final;
		
	q60: //Palavra reservada "prog" encontrada
		printf("\nEntered q60 state. Found reserved word \'prog\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q61:
		printf("\nEntered q61 state");
		(*pointer)++;
		if(isalpha(string[*pointer])) goto q62;
		else goto final;

	q62:
		printf("\nEntered q62 state");
		(*pointer)++;
		if(isalpha(string[*pointer])) goto q62;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q63;
		else goto final;

	q63: //Variável válida encontrada
		printf("\nEntered q63 state. Found valid variable name.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, IDENTIFIER);
		(*pointer)++;
		goto final;
		
	q70:
		printf("\nEntered q70 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q71;
		else goto final;
		
	q71: //Operador "+" encontrado
		printf("\nEntered q71 state. Found operator \'+\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;
		
	q72:
		printf("\nEntered q72 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q73;
		goto final;
		
 	q73: //Operador "-" encontrado
		printf("\nEntered q73 state. Found operator \'-\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;
		
	q75:
		printf("\nEntered q75 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q76;
		else goto final;
		
	q76: //Operador "*" encontrado
		printf("\nEntered q76 state. Found operator \'*\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q77:
		printf("\nEntered q77 state");
		(*pointer)++;
		if(string[*pointer] == '=') goto q81;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q78;
		else goto final;
		
	q78: //Operador "<" encontrado
		printf("\nEntered q78 state. Found operator \'<\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;
		
	q79:
		printf("\nEntered q79 state");
		(*pointer)++;
		if(string[*pointer] == '=') goto q83;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q80;
		
	q80: //Operador ">" encontrado
		printf("\nEntered q80 state. Found operator \'>\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;
		
	q81:
		printf("\nEntered q81 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q82;
		else goto final;
		
	q82: //Operador "<=" encontrado
		printf("\nEntered q82 state. Found operator \'<=\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;
		
	q83:
		printf("\nEntered q83 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q84;
		else goto final;
		
	q84: //Operador ">=" encontrado
		printf("\nEntered q84 state. Found operator \'>=\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;
		
	q85:
		printf("\nEntered q85 state");
		(*pointer)++;
		if(string[*pointer] == '=') goto q89;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q86;
		
	q86: //Operador "=" encontrado
		printf("\nEntered q86 state. Found operator \'=\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q87:
		printf("\nEntered q87 state");
		(*pointer)++;
		if(string[*pointer] == '=') goto q88;
		else goto final;

	q88:
		printf("\nEntered q88 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q91;
		else goto final;

	q89:
		printf("\nEntered q89 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q90;
		else goto final;
		
	q90: //Operador "==" encontrado
		printf("\nEntered q90 state. Found operator \'==\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;
		
	q91: //Operador "!=" encontrado
		printf("\nEntered q91 state. Found operator \'!=\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;
		
	q92:
		printf("\nEntered q92 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q93;
		else goto final;
		
	q93: //Delimitador "(" encontrado
		printf("\nEntered q93 state. Found delimiter \'(\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, DELIMITER);
		(*pointer)++;
		goto final;
		
	q94:
		printf("\nEntered q94 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q95;
		else goto final;
		
	q95: //Delimitador ")" encontrado
		printf("\nEntered q95 state. Found delimiter \')\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, DELIMITER);
		(*pointer)++;
		goto final;
		
	q96:
		printf("\nEntered q96 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q97;
		else goto final;
		
	q97: //Delimitador "," encontrado
		printf("\nEntered q97 state. Found delimiter \',\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, DELIMITER);
		(*pointer)++;
		goto final;
		
	q98:
		printf("\nEntered q98 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q99;
		else goto final;
		
	q99: //Delimitador ";" encontrado
		printf("\nEntered q99 state. Found delimiter \';\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, DELIMITER);
		(*pointer)++;
		goto final;
		
	q100:
		printf("\nEntered q100 state");
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q101;
		else goto final;
		
	q101: //Delimitador "." encontrado
		printf("\nEntered q101 state. Found delimiter \'.\'.\nToken: ");
		writeLexicalItem(initial_pointer, *pointer, string, DELIMITER);
		(*pointer)++;
		goto final;
		
	final:
		printf("\nFinished scanning.");
}

int main() {
	if((saida = fopen("saida.txt", "wt")) == NULL) {
		printf("\nError while opening lexical items file.");
		return 1;
	}
	char string[MAX_LENGTH], result[MAX_LENGTH];
	int pointer = 0;

	printf("\nString to be scanned: ");
	gets(string);
	printf("\nRead: \"%s\"", string);
	scanner(string, &pointer);
	scanner(string, &pointer);
	scanner(string, &pointer);
	
	
	fclose(saida);
}
