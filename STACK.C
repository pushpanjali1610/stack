#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int arr[10];
	int top;
};

int push(struct Stack *s)
{
	if(s->top == 9){
		printf("--->Stack overflow.\n");
		return 0;
	}

	int value;
	printf("Enter any number: \n");
	scanf("%d", &value);

	s->top++;
	s->arr[s->top] = value;
	printf("Value pushed: ");
	printf("%d\n", s->arr[s->top]);

	return 0;
}

int pop(struct Stack *s)
{
	if(s->top < 0){
		printf("--->Stack underflow\n");
		return 0;
	}

	printf("Value popped successfully.\n");
	return s->arr[s->top] && s->top--;
}

int peek(struct Stack *s)
{
	if(s->top < 0){
		printf("--->Stack underflow\n");
		return 0;
	}

	int index;
	printf("Enter the index: \n");
	scanf("%d", &index);

	if(index > s->top){
		printf("Please enter index below %d\n", s->top + 1);
		return 0;
	}

	printf("Value at index %d is %d.\n", index, s->arr[index]);

	return 0;
}

int isEmpty(struct Stack *s)
{
	if(s->top < 0){
		printf("--->Stack is empty.\n");
		return 0;
	}

	else{
		printf("--->Stack is not empty.\n");
		return 0;
	}
}

int isFull(struct Stack *s)
{
	if(s->top == 9){
		printf("--->Stack is full.\n");
		return 0;
	}

	printf("--->Stack is not full\n");
	return 0;
}

int display(struct Stack *s)
{
	if(s->top < 0){
		printf("--->Stack is empty.\n");
		return 0;
	}

	int i = s->top;
	while(i != 0){
		printf("%d\n", s->arr[i]);
		i--;
	}
	printf("%d\n", s->arr[i]);

	// for (int i = s->top; i > 0; i--){
	// 	printf("%d\n", s->arr[i]);
	// }

	return 0;
}

int main()
{
	int option, value;
	struct Stack *s;
	s = (struct Stack *)malloc(sizeof(struct Stack));
	s->top = -1;

	do
	{
		printf("\nEnter an option\n");
		printf("0. Exit\n1. Push\n2. pop\n3. peek\n4. isEmpty\n5. isFull\n6. Display Stack\n7. Clear Screen\n");
		printf("Enter option here: \n");
		scanf("%d", &option);
		switch(option)
		{
			case 0:
				exit(1);
				break;

			case 1:
				push(s);
				break;

			case 2:
				pop(s);
				break;

			case 3:
				peek(s);
				break;

			case 4:
				isEmpty(s);
				break;

			case 5:
				isFull(s);
				break;

			case 6:
				display(s);
				break;

			case 7:
				system("cls");

			default:
				printf("Please enter an appropriate number.\n"	);
		}
	} while (option != 0);

	return 0;
}
