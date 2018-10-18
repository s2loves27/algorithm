template <class T> class Stack{
	public:
		int top;
		int size;
		T *values;

		Stack(){
			size = MAXVALUE;
			values = new T[size];
			top = -1;
		}
		~Stack(){
			delete[] values;
		}
		void push(T value){
			if(!isFull()){
				values[++top] = value;
			}
			else printf("Stack is Full\n");
		}
		void pop(){
			if(!isEmpty()) top--;
			else  printf("Stack is Full\n");
		}

		T Top(){
			if(!isEmpty()) return value[top];
			else return NULL;
		}
		bool isEmpty(){
			if(top < 0) return true;
			else return false;
		}
		bool isFull(){
			if(top+1 == size) return true;
			else return false;
		}
};