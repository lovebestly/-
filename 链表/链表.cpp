// 链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"


//定义结构体
struct Person {
	int age;
	char name[20];
	char gender;
	struct Person * next;
};
//输入数据
void inttialize(struct Person * h, int n) {
	printf("NO.%d\n", n + 1);
	printf("age=");
	scanf_s("%d", &h->age);
	printf("name=");
	getchar();
	scanf_s("%s", h->name, sizeof(h->name));
	printf("gender=");
	getchar();
	scanf_s("%c", &h->gender, sizeof(h->gender));
	h->next = NULL;
}
//创建链表
struct Person * create(int n) {
	struct Person * h = 0, *c = 0, *pre = 0;
	int current = 0;
	while (current < n) {
		c = (struct Person *)malloc(sizeof(struct Person));
		if (current == 0) {
			h = c;
			pre = c;
		}
		else {
			pre->next = c;
			pre = c;
		}
		inttialize(c, current);
		++current;
	}
	return h;
}
//清除链表
void release(struct Person * h) {
	struct Person * c = 0;
	while (h->next != NULL) {
		c = h;
		h = h->next;
		free(c);
	}
	free(h);
}
//遍历链表
void traverse(struct Person * h) {
	struct Person * c = h;
	int current = 0;
	while (c != NULL) {
		printf("NO.%d\n", current + 1);
		printf("age=%d\n", c->age);
		printf("name=%s\n", c->name);
		printf("gender=%c\n", c->gender);
		c = c->next;
		++current;
	}
}
//在末位粘连链表
void append(struct Person * h, int n) {
	struct Person *c = 0;
	while (h = NULL) {
		h = h->next;
	}
	h = create(n);
}
//在链表中插入一个
void insert(struct Person * h, int n) {
	struct Person * c = 0, *tem = 0;
	c = (struct Person *)malloc(sizeof(struct Person));
	inttialize(c, 0);
	while (h->age != n) {
		h = h->next;
	}
	tem = h->next;
	h->next = c;
	c->next = tem;
}
//删除链表中一条
void delete_age(struct Person * h, int n) {
	struct Person * c = 0, *pre = h;
	while (h->age == n) {
		c = h;
		h = h->next;
		free(c);
	}
	pre = h;
	h = h->next;
	while (h != NULL) {
		c = h;
		h = h->next;
		if (c->age == n) {
			pre->next = h;
			free(c);
		}
		else {
			pre = c;
		}
	}
}
//读出链表的长度
int length(struct Person * h) {
	int current = 0;
	while (h != NULL) {
		++current;
		h = h->next;
	}
	return current;
}
//排序
struct Person * sort(struct Person * h) {
	struct Person * c = 0, *n = 0, *pre = 0, *tem = 0;
	int current = 0, count = 1, x = 2;
	count = length(h);
	while (current < count) {
		c = h;
		n = h->next;
		if (c->age < n->age) {
			tem = c;
			c->next = n->next;
			n->next = tem;
			h = n;
			n = c->next;
		}
		else {
			c = n;
			n = n->next;
		}
		pre = h;
		while (x < (count - current)) {
			if (c->age < n->age) {
				tem = c->next;
				c->next = n->next;
				n->next = pre->next;
				pre->next = tem;
				pre = n;
				n = c->next;
			}
			else {
				pre = c;
				c = n;
				n = c->next;
			}
			++x;
		}
		x = 2;
		++current;
	}
	return h;
}

int main()
{
	struct Person * h = NULL;
	int n = 0, age = 0;
	printf("the length is ");
	scanf_s("%d", &n);
	printf("the age is ");
	scanf_s("%d", &age);
	h = create(n);
	traverse(h);
	delete_age(h, age);
	traverse(h);
	release(h);
	printf("hello world!");
	return 0;
}

