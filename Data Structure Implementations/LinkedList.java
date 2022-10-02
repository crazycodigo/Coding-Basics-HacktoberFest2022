package com.Slash;  // This is basically the folder our code belongs to.

public class LinkedList {

    private Node head;  // Reference variable pointing to nodes.
    private Node tail;  // Reference variable pointing to nodes.
    private int size;   // Number of elements in the linked list.
    public LinkedList(){
        this.size=0;
    }

    private class Node {

        private int value;
        private Node next;

        public Node(int value) {
            this.value = value;
        }

        public Node(int value, Node next){
            this.value = value;
            this.next = next;
        }
    }

    // Inserting a new node at the starting of the list.
    public void insertFirst(int val){
        Node node = new Node(val);
        node.next = head;   // Assigning the newly created node to point to the previous head.
        head = node;    // Changing the head to the current node.

        if (tail == null)
            tail = head;    // If this is the only node in the list, then tail also points to this address.

        size += 1;  // Increasing the size of the list coz new element added.
    }

    // Inserting a new node at the end of the list.
    public void insertLast(int val){
        if (tail == null)
            insertFirst(val);
        else {
            Node node = new Node(val);
            tail.next = node;
            tail = node;
            size += 1;
        }
    }

    // Inserting a new node at any given list
    public void insert(int val, int index){
        if (index == 0) {
            insertFirst(val);
            return;
        }

        if(index == size){
            insertLast(val);
            return;
        }

        Node temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp.next;   // Reaching before the node where we want to insert our value.
        }
        Node node = new Node(val, temp.next);   // Pointing the new node to the next value of the temporary node.
        temp.next = node;
        size++;
        }

    // Delete node at the first index.
    public int deleteFirst(){
        int val = head.value;
        head = head.next;
        if(head==null){
            tail = null;
        }
        size -= 1;
        return val;
    }

    // Delete node at the last index.
    public int deleteLast(){
        if(size <= 1){
            return deleteFirst();
        }

        Node secondLast = get(size - 2);
        int value = tail.value;
        tail = secondLast;
        tail.next = null;
        size -= 1;
        return value;
    }

    // To delete a node at given index.
    public int delete(int index){
        if (index == 0)
            return deleteFirst();
        if (index == size-1)
            return deleteLast();
        Node prev = get(index - 1);
        Node deleted = prev.next;
        int val = deleted.value;
        prev.next = deleted.next;
        size -= 1;
        return val;
    }

    // To return a node that has a particular value.
    public Node find(int value){
        Node node = head;
        while(node != null){
            if(node.value == value)
                return node;
            node = node.next;
        }
        return null;
    }

    // To return a node at a particular index.
    public Node get(int index){
        Node node = head;
        for (int i = 0; i < index; i++) {
            node = node.next;
        }
        return node;
    }

    // Displaying the entire linked list.
    public void displayList(){
        Node temp = head;
        while(temp != null) {
            System.out.print(temp.value + "-->");
            temp = temp.next;
        }
        System.out.println("END");
    }
}
