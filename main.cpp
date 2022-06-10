#include <iostream>
using namespace std;



template <class T> class Linked_Stack {
private:
	struct Node {
		T value;
		Node* next;
	};
	Node* top = NULL;


public:
	void pushNode(T v);
	bool isEmpty();
	void popNode();
	T popNodeWithReturnTheLastValue();
	T peek();
	void display();
	T getElements();
};



bool arePaired(char open, char close) {
	if (open == '(' && close == ')') {
		return true;
	}
	else if (open == '[' && close == ']') {
		return true;
	}
	else if (open == '{' && close == '}') {
		return true;
	}
	else {
		return false;
	}
}

bool areBalanced(string text) {
	Linked_Stack <char>s;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == '(' || text[i] == '[' || text[i] == '{') {
			s.pushNode(text[i]);
		}
		else if (text[i] == ')' || text[i] == ']' || text[i] == '}') {
			if (s.isEmpty()) {
				return false;
			}

			if (arePaired(s.peek(), text[i])) {
				s.popNode();
			}
		}
	}

	return s.isEmpty();
}



int main(void) {	
	
	string text;
	cout << "Please enter a text: ";
	cin >> text;

	if (areBalanced(text)) {
		cout << "Balanced.\n";
	}
	else {
		cout << "Not balanced.\n";
	}

	



	return 0;
}





template <class T> void Linked_Stack<T>::pushNode(T v) {
	Node* newNode = new Node;
	newNode->value = v;
	newNode->next = top;
	top = newNode;

}

template <class T> bool Linked_Stack<T>::isEmpty() {
	return top == NULL; // If top = NULL, it means the stack is empty so it should return True (1).
}

template <class T> void Linked_Stack<T>::popNode() {
	if (top == NULL) {
		cout << "This linked-stack is empty.\n";
	}
	else {
		Node* temp = top;
		top = top->next;
		free(temp);
	}

}

template <class T> T Linked_Stack<T>::popNodeWithReturnTheLastValue() {
	if (top == NULL) {
		cout << "This linked-stack is empty.\n";
	}
	else {
		Node* temp = top;
		T topValue = top->value;
		top = top->next;
		free(temp);
		return topValue;
	}
}

template <class T> T Linked_Stack<T>::peek() {
	return top->value;
}

template <class T> void Linked_Stack<T>::display() {
	Node* temp = top;
	
	while (temp != NULL) {
		cout << temp->value << endl;
		temp = temp->next;
	}
}

template <class T> T Linked_Stack<T>::getElements() {
	static Node* temp = top;
	static int i = 0;
	i++;
	if (i == 1) {
		return temp->value;
	}
	else {
		temp = temp->next;
		return temp->value;
	}
}
