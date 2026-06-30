/**
 * @FilePath     : /learn-cpp-note/queue/LinkedQueue.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-30 11:52:53
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-30 12:57:33
**/
#pragma once



template<class T>
class LinkedQueue
{
    struct Node {
        T data;
        Node* next;
    };

    using NodePtr   = Node*;
private:
    NodePtr head_;
    NodePtr tail_;
public:
    LinkedQueue() : head_{}, tail_{} {

    }
    
    ~LinkedQueue() {
        clear();
    }

    LinkedQueue(const LinkedQueue&) = delete;
    LinkedQueue& opeartor=(const LinkedQueue&) = delete;
    LinkedQueue(LinkedQueue&&) = delete;
    LinkedQueue& operator=(LinkedQueue&&) = delete;

    void push(const T& val) {
        NodePtr node = new Node{val, nullptr};
        
        if (!head_) {
            head_ = node;
            tail_ = node;
        } else {
            tail_->next = node;
            tail_ = node;
        }
    }

    void push(T&& val) {
        NodePtr node = new Node{std::move(val), nullptr};
        
        if (!head_) {
            head_ = node;
            tail_ = node;
        } else {
            tail_->next = node;
            tail_ = node;
        }
    }

    bool pop(T& val) {
        if (head_) {
            NodePtr next = head_->next;
            val = std::move(head_->data);
            delete head_;
            head_ = next;

            if (!head_) tail_ = nullptr;

            return true;
        }
        return false;
    }

    void clear() {
        while (head_) {
            NodePtr next = head_->next;
            delete(head_);
            head_ = next;
        }
        tail_ = nullptr;
    }
};