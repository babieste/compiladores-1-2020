
// Barbara Este Fernandez - 31937039

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define RESERVED_WORD "RESERVED_WORD"
#define IDENTIFIER "IDENTIFIER"
#define BOOLEAN "BOOLEAN"
#define OPERATOR "OPERATOR"
#define DELIMITER "DELIMITER"
#define INT "INT"
#define FLOAT "FLOAT"
#define COMMENT "COMMENT"

FILE *lexical_tokens;

void getToken(char *token_type, char *token_value) {
	// Tokens are written in the format: "<TOKEN_TYPE, TOKEN_VALUE>"
	int i = 1; //Skips "<"
	char *token_variable;
	fgets(token_variable, 255, lexical_tokens);
	
	//Cleans trash if any
	memset(token_value, 0, 255);
	memset(token_type, 0, 255);

	while (token_variable[i] != ',') {
		strncat(token_type, &token_variable[i], 1);
		i++;
	}
	
	printf("\ntoken_type: %s", token_type);
	i++; //Skips " "
	
	while (token_variable[i] != '>') {
		strncat(token_value, &token_variable[i], 1);
		i++;
	}
	printf("\ntoken_value: %s", token_value);
}

int match(char token_type[], char token_value[]) {
	char lookahead[255], lookahead_type[255];
	getToken(lookahead_type, lookahead);

	if(strcmp(token_type, IDENTIFIER) == 0)
		return 1;

	if ((strcmp(lookahead, token_value) == 0) && (strcmp(lookahead_type, token_type)))
		return 1;
	return 0;
}

/* <programa> ::= prog <identificador> <bloco> fim . */
//int programa() {
//	if (match(RESERVED_WORD,"prog") && identificador() && bloco() && match(RESERVED_WORD,"fim") && match(DELIMITER,"."))
//		return 1;
//	return 0;
//}

/* <identificador> ::= id*/
int identificador() {
	if(match(IDENTIFIER, ""))
		return 1;
	return 0;
}

/* <declaracao_variavel> ::= (int | bool) <identificador> ; */
int declaracaoVariaveis() {
	if ((match(RESERVED_WORD, "int") || match(RESERVED_WORD, "boolean")) && identificador() && match(DELIMITER, ";"))
		return 1;
	return 0;
}

void writeLexicalItem(int initial, int final, char *string, char* type) {
	int i = initial;
	fputc('<', lexical_tokens);
	fputs(type, lexical_tokens);
	fputs(", ", lexical_tokens);
	while(i < final) {
		fputc(string[i], lexical_tokens);
		i++;
	}
	fputs(">\n", lexical_tokens);
}

char *scanner(char string[],int *initial_pointer, int *pointer) {
	int tam = 0;
	*initial_pointer = *pointer;
	goto q0;

	q0: //Estado inicial
		if(string[*pointer] == 't') goto q1;
		if(string[*pointer] == 'f') goto q2;
		if(string[*pointer] == 'p') goto q3;
		if(string[*pointer] == 's') goto q14;
		if(string[*pointer] == 'b') goto q17;
		if(string[*pointer] == 'i') goto q22;
		if(string[*pointer] == 'e') goto q26;
		if(string[*pointer] == 'r') goto q40;
		if(string[*pointer] == '_') goto q61;
		if(string[*pointer] == '/') goto q64;
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
		if(isdigit(string[*pointer])) goto q110;
		else goto final;

	q1:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q01;
		else goto final;

	q2:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q34;
		if(string[*pointer] == 'i') goto q35;
		else goto final;

	q3:
		(*pointer)++;
		if(string[*pointer] == 'r') goto q4;
		else goto final;

	q4:
		(*pointer)++;
		if(string[*pointer] == 'o') goto q5;
		else goto final;

	q5:
		(*pointer)++;
		if(string[*pointer] == 'c') goto q47;
		if(string[*pointer] == 'g') goto q6;
		else goto final;

	q6:
		(*pointer)++;
		if(string[*pointer] == 'r') goto q7;
		else goto final;

	q7:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q60;
		else goto final;

	q8:
		(*pointer)++;
		if(string[*pointer] == 'a') goto q9;
		else goto final;

	q9:
		(*pointer)++;
		if(string[*pointer] == 'o') goto q10;
		else goto final;

	q10:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q11;
		else goto final;

	q11: //Palavra reservada "senao" encontrada
		writeLexicalItem(*initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q12:
		(*pointer)++;
		if(string[*pointer] == 't') goto q13;
		else goto final;

	q13:
		(*pointer)++;
		if(string[*pointer] == 'a') goto q49;
		else goto final;

	q14:
		(*pointer)++;
		if(string[*pointer] == 'e') goto q15;
		else goto final;

	q15:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q16;
		if(string[*pointer] == 'n') goto q8;
		else goto final;

	q16: //Palavra reservada "se" encontrada
		writeLexicalItem(*initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q17:
		(*pointer)++;
		if(string[*pointer] == 'o') goto q18;
		else goto final;

	q18:
		(*pointer)++;
		if(string[*pointer] == 'o') goto q19;
		else goto final;

	q19:
		(*pointer)++;
		if(string[*pointer] == 'l') goto q20;
		else goto final;

	q20:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q21;
		else goto final;

	q21: //Palavra reservada "bool" encontrada
		writeLexicalItem(*initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q22:
		(*pointer)++;
		if(string[*pointer] == 'n') goto q23;
		else goto final;

	q23:
		(*pointer)++;
		if(string[*pointer] == 't') goto q24;
		else goto final;

	q24:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q25;
		else goto final;

	q25: //Palavra reservada "int" encontrada
		writeLexicalItem(*initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q26:
		(*pointer)++;
		if(string[*pointer] == 's') goto q27;
		if(string[*pointer] == 'n') goto q12;
		else goto final;

	q27:
		(*pointer)++;
		if(string[*pointer] == 'c') goto q28;
		else goto final;

	q28:
		(*pointer)++;
		if(string[*pointer] == 'r') goto q29;
		else goto q29;

	q29:
		(*pointer)++;
		if(string[*pointer] == 'e') goto q30;
		else goto final;

	q30:
		(*pointer)++;
		if(string[*pointer] == 'v') goto q31;
		else goto final;

	q31:
		(*pointer)++;
		if(string[*pointer] == 'a') goto q32;
		else goto final;

	q32:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q33;
		else goto final;

	q33: //Palava reservada "escreva" encontrada
		writeLexicalItem(*initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

 	q34: //Booleano t encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, BOOLEAN);
		(*pointer)++;
		goto final;

	q35:
		(*pointer)++;
		if(string[*pointer] == 'm') goto q36;
		else goto final;

	q36:
		(*pointer)++;
		if(string[*pointer] == 's') goto q37;
		else goto final;

	q37:
		(*pointer)++;
		if(string[*pointer] == 'e') goto q38;
		else goto final;

	q38:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q39;
		else goto final;

	q39: //Palavra reservada "fimse" encontrada
		writeLexicalItem(*initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q40:
		(*pointer)++;
		if(string[*pointer] == 'e') goto q41;
		else goto final;

	q41:
		(*pointer)++;
		if(string[*pointer] == 'p') goto q42;
		else goto final;

	q42:
		(*pointer)++;
		if(string[*pointer] == 'i') goto q43;
		else goto final;

	q43:
		(*pointer)++;
		if(string[*pointer] == 't') goto q44;
		else goto final;

	q44:
		(*pointer)++;
		if(string[*pointer] == 'a') goto q45;
		else goto final;

	q45:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q46;
		else goto final;

	q46: //Palava reservada "repita" encontrada
		writeLexicalItem(*initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q47:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q48;
		else goto final;

	q48: //Palavra reservada "proc" encontrada
		writeLexicalItem(*initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q49:
		(*pointer)++;
		if(string[*pointer] == 'o') goto q50;
		else goto final;

	q50:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q51;

	q51: //Palava reservada "entao" encontrada
		writeLexicalItem(*initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q01: //Booleano t encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, BOOLEAN);
		(*pointer)++;
		goto final;

	q60: //Palavra reservada "prog" encontrada
		writeLexicalItem(*initial_pointer, *pointer, string, RESERVED_WORD);
		(*pointer)++;
		goto final;

	q61:
		(*pointer)++;
		if(isalpha(string[*pointer])) goto q62;
		else goto final;

	q62:
		(*pointer)++;
		if(isalpha(string[*pointer])) goto q62;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q63;
		else goto final;

	q63: //Variavel valida encontrada
		writeLexicalItem(*initial_pointer, *pointer, string, IDENTIFIER);
		(*pointer)++;
		goto final;

	q64:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q74;
		if(string[*pointer] == '*') goto q66;

	q65:
		(*pointer)++;
		if(string[*pointer] == '*') goto q67;
		else goto q65;

	q66:
		(*pointer)++;
		goto q65;

	q67:
		(*pointer)++;
		if(string[*pointer] == '/') goto q68;
		else goto q65;

	q68:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q69;
		else goto final;

	q69: //Coment�rio v�lido encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, COMMENT);
		(*pointer)++;
		goto final;

	q70:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q71;
		if(isdigit(string[*pointer])) goto q102;
		else goto final;

	q71: //Operador "+" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q72:
		(*pointer)++;
		if(isdigit(string[*pointer])) goto q106;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q73;
		goto final;

 	q73: //Operador "-" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q74: //Operator "/" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q75:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q76;
		else goto final;

	q76: //Operador "*" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q77:
		(*pointer)++;
		if(string[*pointer] == '=') goto q81;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q78;
		else goto final;

	q78: //Operador "<" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q79:
		(*pointer)++;
		if(string[*pointer] == '=') goto q83;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q80;

	q80: //Operador ">" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q81:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q82;
		else goto final;

	q82: //Operador "<=" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q83:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q84;
		else goto final;

	q84: //Operador ">=" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q85:
		(*pointer)++;
		if(string[*pointer] == '=') goto q89;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q86;

	q86: //Operador "=" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q87:
		(*pointer)++;
		if(string[*pointer] == '=') goto q88;
		else goto final;

	q88:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q91;
		else goto final;

	q89:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q90;
		else goto final;

	q90: //Operador "==" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q91: //Operador "!=" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, OPERATOR);
		(*pointer)++;
		goto final;

	q92:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q93;
		else goto final;

	q93: //Delimitador "(" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, DELIMITER);
		(*pointer)++;
		goto final;

	q94:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q95;
		else goto final;

	q95: //Delimitador ")" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, DELIMITER);
		(*pointer)++;
		goto final;

	q96:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q97;
		else goto final;

	q97: //Delimitador "," encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, DELIMITER);
		(*pointer)++;
		goto final;

	q98:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q99;
		else goto final;

	q99: //Delimitador ";" encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, DELIMITER);
		(*pointer)++;
		goto final;

	q100:
		(*pointer)++;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q101;
		else goto final;

	q101: //Delimitador "." encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, DELIMITER);
		(*pointer)++;
		goto final;

	q102:
		(*pointer)++;
		if(isdigit(string[*pointer])) goto q102;
		if(string[*pointer] == '.') goto q104;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q103;

	q103: //N�mero inteiro positivo encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, INT);
		(*pointer)++;
		goto final;

	q104:
		(*pointer)++;
		if(isdigit(string[*pointer])) goto q104;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q105;
		else goto final;

	q105: //N�mero decimal positivo encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, FLOAT);
		(*pointer)++;
		goto final;

	q106:
		(*pointer)++;
		if(isdigit(string[*pointer])) goto q106;
		if(string[*pointer] == '.') goto q108;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q107;
		else goto final;

	q107: //Numero inteiro negativo encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, INT);
		(*pointer)++;
		goto final;

	q108:
		(*pointer)++;
		if(isdigit(string[*pointer])) goto q108;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q109;
		else goto final;

	q109: //Numero decimal negativo encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, FLOAT);
		(*pointer)++;
		goto final;

	q110:
		(*pointer)++;
		if(isdigit(string[*pointer])) goto q110;
		if(string[*pointer] == '.') goto q112;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q111;
		else goto final;

	q111: //Numero inteiro sem sinal encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, INT);
		(*pointer)++;
		goto final;

	q112:
		(*pointer)++;
		if(isdigit(string[*pointer])) goto q112;
		if(isspace(string[*pointer]) || (string[*pointer] == '\0')) goto q113;
		else goto final;

	q113: //Numero decimal sem sinal encontrado
		writeLexicalItem(*initial_pointer, *pointer, string, FLOAT);
		(*pointer)++;
		goto final;

	final:
		printf("");
}

int main() {
	FILE * entrada;
	if ((entrada = fopen("entrada2.txt", "r")) == NULL) {
		printf("\nError while opening program file");
		return 1;
	}

	if((lexical_tokens = fopen("lexical_tokens.txt", "w+")) == NULL) {
		printf("\nError while opening lexical tokens file.");
		return 1;
	}
	char word[255], token_type[255], token_value[255];
	char string[10000];
	int initial_pointer = 0, pointer = 0;

	while(!feof(entrada)) {
		fscanf(entrada, "%s", word);
		strcat(string, word);
		strcat(string, " ");
	}

	printf("\n%s", string);

	//Get lexical items from program
	do {
		scanner(string, &initial_pointer, &pointer);
	} while(initial_pointer < pointer);

	fseek(lexical_tokens, 0, SEEK_SET);
	
//	getToken(token_type, token_value);
	if(declaracaoVariaveis()) {
		printf("\nReconhecido!");
	} else {
		printf("\nNao foi reconhecido!");
	}

	fclose(entrada);
	fclose(lexical_tokens);
	return 0;
}
