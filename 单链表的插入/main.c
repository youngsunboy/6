#include <stdio.h>
#include <stdlib.h>

//����һ�����͵�����
typedef char datatype;
//������ṹ��
typedef struct node {
	datatype data;
	struct node* next;
}linklist;

linklist* CreatListR() {
	//��ͷ����β�巨�����ص������ͷָ��
	linklist* head, * p, * r;
	datatype ch;
	head = (linklist*)malloc(sizeof(linklist));//����ͷ���
	head->next = NULL;
	r = head;//rָ��ָ��ͷ���
	while ((ch = getchar()) != '\n') {
		p = (linklist*)malloc(sizeof(linklist));//�����½��
		p->data = ch;//�Խ�����������и�ֵ
		r->next = p;//�½��ָ���β
		r = p;//rָ��ָ���±�β
	}
	r->next = NULL;
	return head;
}
linklist* Get(linklist* head, int i) {
	linklist* p = head;//pָ��ͷ���
	int j = 0;
	while (p->next != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (i == j) {
		return p;
	}
	else {
		return NULL;
	}
}
void Insert(linklist* L, datatype x, int i) {
	//Lָ�����ͷ���ĵ�����
	linklist* p, * s;
	p = Get(L, i-1);
	if (p == NULL) printf("���Ҳ���i-1�����");
	else {
		//���½�����p֮��
		s = (linklist*)malloc(sizeof(linklist));
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
}
//������
int main() {
	linklist* head = (linklist*)malloc(sizeof(linklist));
	linklist* p = (linklist*)malloc(sizeof(linklist));
	head = CreatListR();
	int i;
	printf("������Ҫ����λ�õ����:");
	scanf_s("%d", &i);
	printf("��������Ҫ������ַ�:");
	getchar();
	datatype ch = getchar();
	Insert(head, ch, i);
	p = head->next;
	while (p != NULL) {
		printf("%c", p->data);
		p = p->next;
	}
	system("pause");
	return 0;
}