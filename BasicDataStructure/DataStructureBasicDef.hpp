//
//  DataStructureBaseDef.cpp
//  use togrther with DataStructureBasic1
//
//  Created by KevinLiu on 16/12/11.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

/*
A avaible way to solve the problem in Class Template:
  create a .hpp file to implement method in class template
*/

#ifndef DataStructureBasicDef_hpp
#define DataStructureBasicDef_hpp

#include "DataStructureBasic1.hpp"

//Implemenet

template<typename T>
Node<T>::Node():next(NULL)
{
}

template<typename T>
Node<T>::Node(const T& ele)
{
    this->element = ele;
    next = NULL;
}

template<typename T>
LinkedList<T>::LinkedList()
{
    head = tail = NULL;
    size = 0;
}

template<typename T>
void LinkedList<T>::print()
{
    if (getSize() == 0)
    {
        cout << "Empty list."<< endl;
    }
    else
    {
        for (int i = 0; i < getSize(); ++i) {
            cout << get(i) << " ";
        }
        cout << endl;
        cout<<"current list length: "<<getSize()<<endl;
    }
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
    //    if (head == NULL)
    //        return true;
    //    else
    //        return false;
    
    return head==NULL;
}

template<typename T>
void LinkedList<T>::clear()
{
    while (head!=NULL) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    
    tail = NULL;
}

template<typename T>
int LinkedList<T>::indexOf(const T element)
{
    Node<T> *current = head;
    for (int i = 0; i <size; ++i) {
        if(current->element == element)
            return i;
        current = current->next;
    }
    
    return -1;
}

template<typename T>
const int LinkedList<T>::getSize()
{
    return size;
}

template<typename T>
void LinkedList<T>::addFirst(const T element)
{
    Node<T> *newNode = new Node<T>(element);//creat new Node
    
    newNode->next = head;
    head = newNode;
    ++size;
    
    if(tail == NULL)//if list was empty, both tail and head pointer to newNode
        tail = head;
}

template<typename T>
void LinkedList<T>::addLast(const T element)
{
    Node<T> *newNode=new Node<T>(element);
    
    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
    
    ++size;
}


template<typename T>
void LinkedList<T>::add(const T element)
{
    addLast(element);
}

template<typename T>
void LinkedList<T>::add(const int index, const T element)
{
    if (index == 0)
        addFirst(element);
    else if(index >= size)
        addLast(element);
    else
    {
        Node<T>* p = head;
        Node<T>* newNode=new Node<T>(element);
        for (int i = 1; i < index; ++i)
            p = p->next;//p pointer to one ahead the position to be insert
        
        Node<T>* temp = p->next;
        p->next = newNode;
        newNode->next = temp;
        
        ++size;
    }
}

template<typename T>
const T LinkedList<T>::getFirst()
{
    if(size == 0)
        throw runtime_error("Index out of range");
    else
        return head->element;
}

template<typename T>
const T LinkedList<T>::getLast()
{
    if(size == 0)
        throw runtime_error("Index out of range");
    else
        return tail->element;
}

template<typename T>
const T LinkedList<T>::get(const int index)
{
    if(index < 0 || index > size-1)
        throw runtime_error("Index out of range");
    
    Node<T>* current = head;
    for(int i = 0;i < index;++i)//locate current
        current = current->next;
    
    return current->element;
}

template<typename T>
T LinkedList<T>::removeFirst() throw(runtime_error)//throw exception
{
    if(size==0)
        throw runtime_error("No elements in the list");
        else
        {
            Node<T>* p = head;//p as the same meaning of "temp"
            head = head->next;
            --size;
            //    p->next = nullptr;
            //    return (*p).elemet; my wrong thought
            if(head == NULL) tail = NULL;
                
                T element = p->element;
                delete p;//distroy the node
            return element;
        }
}

template<typename T>
T LinkedList<T>::removeLast() throw(runtime_error)
{
    if(size==0)
        throw runtime_error("No elements in the list");
        else if(size == 1)
        {
            Node<T>* temp = head;
            head = tail = NULL;
            size = 0;
            T element = temp->element;
            delete temp;
            return element;
        }
        else
        {
            Node<T>* p = head;
            while(p->next != tail)
                p = p->next;// p pointer to the one ahead from tail
                
                T element = (p->next)->element;//return element to be delete
                tail = p;
                tail->next = NULL;
                
                --size;
            
            delete p;
            return element;
        }
}

template<typename T>
T LinkedList<T>::removeAt(const int index)
{
    if(index == 0)
        return removeFirst();
    else if(index == size-1)
        return removeLast();
    else
    {
        Node<T>* previous = head;
        for(int i = 1;i < index;++i)
            previous = previous->next;//locate previous
        
        Node<T>* current = previous->next;
        previous->next = current->next;
        
        --size;//reduce size
        
        T element = current->element;
        delete current;
        return element;
    }
}

#endif
