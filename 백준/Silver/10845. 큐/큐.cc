#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


struct linked_list {
	int data;
	struct linked_list* link;
};

class queue
{
public:
	linked_list* head;
	linked_list* tail;
	int len;
	void push(int n);
	void pop();
	void size();
	void empty();
	void front();
	void back();
	queue();
private:


};

queue::queue() {
	len = 0;
}

void queue::push(int n) {
	if (len == 0) {
		len++;
		linked_list* node= (linked_list*)malloc(sizeof(linked_list));
		node->data = n;
		head = node;
		tail = node;
	}
	else
	{
		linked_list* node = (linked_list*)malloc(sizeof(linked_list));
		node->data = n;

		tail->link =node;
		tail = node;
		len++;
	}
}

void queue::pop() {
	if (len == 0) {
		cout << -1 << endl;
	}
	else
	{
		cout << head->data << endl;
		linked_list* node = head;
		head = node->link;
		free(node);
		len--;
	}
}

void queue::size() {
	cout << len << endl;
}

void queue::empty() {

	if (len == 0) {
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}

void queue::front() {

	if (len == 0) {
		cout << -1 << endl;
	}
	else
	{
		cout << head->data << endl;
	}
}

void queue::back() {

	if (len == 0) {
		cout << -1 << endl;
	}
	else
	{
		cout << tail->data << endl;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	string m;
	int data;

	queue nq;

	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == "push") {
			cin >> data;
			nq.push(data);
		}
		else if (m == "pop") {
			nq.pop();
		}
		else if (m == "size") {
			nq.size();
		}
		else if (m == "empty") {
			nq.empty();
		}
		else if (m == "front") {
			nq.front();
		}
		else if (m == "back") {
			nq.back();
		}
	}
}
