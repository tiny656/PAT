ElementType EvalPostfix(char *expr) {
  ElementType stack[Max_Expr+10];
  int top = -1;
  char *p = expr;
  char token[Max_Expr];

  while (*p) {
      int i = 0;
      // Skip spaces
      while (*p == ' ') p++;
      if (!*p) break;

      // Get next token
      while (*p && *p != ' ') {
          token[i++] = *p++;
      }
      token[i] = '\0';

      // Process token
      if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
          // Not enough operands
          if (top < 1) return Infinity;

          ElementType op2 = stack[top--];
          ElementType op1 = stack[top--];

          switch (token[0]) {
              case '+':
                  stack[++top] = op1 + op2;
                  break;
              case '-':
                  stack[++top] = op1 - op2;
                  break;
              case '*':
                  stack[++top] = op1 * op2;
                  break;
              case '/':
                  // Division by zero check
                  if (op2 == 0) return Infinity;
                  stack[++top] = op1 / op2;
                  break;
          }
      } else {
          // Convert string to number
          ElementType num;
          if (sscanf(token, "%lf", &num) != 1) return Infinity;
          stack[++top] = num;
      }
  }

  // Final stack should have exactly one value
  if (top != 0) return Infinity;

  return stack[top];
}