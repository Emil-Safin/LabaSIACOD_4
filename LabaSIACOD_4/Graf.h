#pragma once
#ifndef GRAF_H
#define GRAF_H
using namespace System;
class Graf{
	Graf* pNext;
	int num;
	bool v = false;
    int Size;
public:
	Graf* arr[60];// = new Graf * [10];
	Graf() {
		for (int i = 0; i < 60; i++) {
			arr[i] = nullptr;
		}
		this->num = 0;
	}
	Graf(int num){
		for (int i = 0; i < 60; i++) {
			arr[i] = nullptr;
		}
		this->num = num;
	}
	Graf(const Graf &a) {
		for (int i = 0; i < 60; i++) {
			arr[i] = a.arr[i];
		}
		this->num = a.num;
	}

	void add(int num, Graf* pNext) {
		int i = 0;
		while (arr[i] != nullptr) {
			i++;
		}
		arr[i] = pNext;
	}
	bool visited() {
		return v;
	}
	void setVisited(bool v) { this->v = v; }
	int getNum() { return num; }

	String^ obhod() {
		String ^s;
		int mas[25];
		int counter = 0;
		setVisited(true);
		for (int i = 0; arr[i] != nullptr; i++) {
		//	mas[i] = '\0';
			if (!arr[i]->visited()) {
				s += (arr[i]->num).ToString() + " ";
				mas[counter] = i;
				arr[i]->setVisited(true);
			counter++;
			}
		}
		for (int i = 0; i < counter; i++) {
			//if (!arr[mas[i]]->visited()) {
				s += (arr[mas[i]]->obhod())+ " ";
			//}
		}
		return s;

	}

};
#endif
