%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid = 0, i, j, k, temp = 0, temp1, top = 1;
int num[40];
char arr[40][10], st[80], op[40];
%}

%%
[a-zA-Z][a-zA-Z0-9]* {
    strcpy(arr[j++], yytext);
    if (st[top - 1] == 'i')
        valid = 1;
    else if (st[top - 1] == 'o')
        st[top - 1] = 'i';
    else
        st[top++] = 'i';
}

[0-9]+ {
    num[k++] = atoi(yytext);
    if (st[top - 1] == 'i')
        valid = 1;
    else if (st[top - 1] == 'o')
        st[top - 1] = 'i';
    else
        st[top++] = 'i';
}

[\-+/*%^&|=] { // Added '=' for assignment
    op[temp++] = yytext[0];
    if (st[top - 1] == 'i')
        st[top - 1] = 'o';
    else
        valid = 1;
}

"(" {
    if (st[top - 1] == '(' || st[top - 1] == '$' || st[top - 1] == 'o')
        st[top++] = '(';
    else
 valid = 1;
}

")" {
    if (st[top - 1] == '(')
        top--;
    else if (st[top - 1] == 'i' && st[top - 2] == '(') {
        top -= 2;
        if (st[top - 1] == 'o')
            st[top - 1] = 'i';
        else if (st[top - 1] == 'i')
            valid = 1;
        else
            st[top++] = 'i';
    } else {
        valid = 1;
    }
}

. {
    valid = 1;
}

\n {
    return 0;
}
%%

int check() {
    if (!(temp || k || j))
        return 0;
    if (valid)
        return 0;
    if (top == 2 && st[top - 1] == 'i')
        top--;
    if (top == 1 && st[top - 1] == '$')
        top--;
    if (top == 0)
        return 1;
    return 0;
}
int main() {
    st[top - 1] = '$';
    printf("\nEnter the expression: ");
    yylex();
    if (check()) {
        printf("\nValid expression!\n");
        if (j > 0) {
            printf("\nIdentifiers present are: ");
            for (i = 0; i < j; i++)
                printf("\n%s", arr[i]);
        }
        if (k > 0) {
            printf("\nNumbers used are: ");
            for (i = 0; i < k; i++)
                printf("\n%d", num[i]);
        }
        if (temp > 0) {
            printf("\nOperators present are: ");
            for (i = 0; i < temp; i++)
                printf("\n%c", op[i]);
        }
    } else {
        printf("\nInvalid expression!\n");
    }
    return 0;
}

int yywrap(void) {
    return 1;
}


