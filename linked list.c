#include <stdio.h>
#include <stdlib.h>

typedef struct ListNODE{	// 구조체 정의
	int data; //데이터 변수 저장 
	struct ListNODE *prev;	// 앞의 전 노드 
	struct ListNODE *next;	// 뒤의 다음 노드
}NODE;

NODE *head, *tail;

NODE *makenode(int data) {	// 노드 생성
	NODE *p = (NODE *)malloc(sizeof(NODE)); // 포인트 변수ㅗㄹ 동적 할당을 이용해 변수를 만들 수 있게 함 
	p -> data = data;
	p -> next = NULL;
	p -> prev = NULL;
	return p;
}

void print() {	// 출력
	NODE *p;
	p = head;
	while (p -> next != tail){
		printf(" %d-->", p -> data);
		p = p -> next;
	}
	printf(" %d ", p -> data); puts("출력 끝");
}

void Resetnode() {	// 모든 노드 초기화 시킴
	head = (NODE *)malloc(sizeof(NODE));
	tail = (NODE *)malloc(sizeof(NODE));
	head -> data = 0;
	tail -> data = 0;

	head -> next = tail;
	head -> prev = head;
	tail -> prev = head;
	tail -> next = tail;
}

void insertnode(int data){	// 노드 삽입
	NODE *newnode = makenode(data);
	NODE *p;
	p = tail;
	p -> prev -> next = newnode;  //노드 pre의 오른쪽 노드를 삽입할 노드 NEW의 오른쪽 노드로 연결
	newnode -> prev = p -> prev;//새 노드 NEW의 주소를 노드 pre의 rlink에 저장하여 노드 NEW를 노드 pre의 오른쪽 노드로 연결
	p -> prev = newnode; //포인터 pre의 값을 삽입할 노드 NEW의 llink에 저장하여 노드 pre를 노드 NEW의 왼쪽 노드로 연결
	newnode -> next = p; //포인터 NEW의 값을 노드 NEW의 오른쪽 노드(NEW.rlink)의 llink에 저장하여 노드 NEW의 오른쪽 노드의 왼쪽 노드로 노드 NEW를 연결
}

void deletenode(int val){	// 삭제
	NODE *p;
	p = head -> next;
	while(p -> next != tail){
		if(p -> data == val){
			p -> next -> prev = p -> prev;//삭제할 노드의 오른쪽 노드의 주소(old.rlink)를 삭제할 노드의 왼쪽 노드(old.llink)의 오른쪽 링크(rlink)에 저장
			p -> prev -> next = p -> next;// 삭제할 노드의 왼쪽 노드의 주소(old.llink)를 삭제할 노드의 오른쪽 노드(old.rlink)의 왼쪽 링크(llink)에 저장
			free(p); //할당 해제 
			return;
		}
		p = p -> next;
	}
}

void main() {
	Resetnode();
	insertnode(40);
	insertnode(60);
	insertnode(80);
    insertnode(100);
    puts(" 삽입 시작 ");
	print();
	puts(" 삭제 시작");
	deletenode(60);
    deletenode(80);
    print();
}