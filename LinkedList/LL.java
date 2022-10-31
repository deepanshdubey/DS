class LL
{
    Node head;
    private int size;
    LL()
    {
        this.size = 0;
    }
    class Node{
        String data;
        Node next;

        Node(String data){
            this.data = data;
            this.next = null;
        }
    }

    // add-first

    public void addFirst(String data)
    {
        size++;

        Node newNode = new Node(data);
        if(head == null)
        {
            head = newNode;
            return;
        }

        newNode.next = head;
        head = newNode;

    }

    // add-last

    public void addLast(String data)
    {
        size++;

        Node newNode = new Node(data);
        if(head == null)
        {
            head = newNode;
            return;
        }
        Node currNode = head;
        while(currNode.next != null)
        {
            currNode = currNode.next;
        }
        currNode.next = newNode;


    }

    //print

    public void printList()
    {
        if(head == null)
        {
            System.out.println("List is empty");
            return;
        }
        Node currNode = head;
        while(currNode != null)
        {
            System.out.print(currNode.data + " -> ");
            currNode = currNode.next;
        }
        System.out.println("NULL");
    }

    // delete-first
    public void deleteFirst()
    {
        if(head == null)
            {
                System.out.println("List is empty");
                return;
            }
            head = head.next; 

            size--;
    }

    public void deleteLast()
    {
        if(head == null)
        {
            System.out.println("List is empty");
            return;
        }

        size--;


        if(head.next == null)
        {
            head = null;
            return;
        }
        Node secondLast = head;
        Node lastNode = head.next;
        while(lastNode.next != null)
        {
            lastNode = lastNode.next;
            secondLast = secondLast.next;
        }
        secondLast.next = null;


    }

    // size

    public int getSize() 
    {
        return size;
        
    }

    public void reverseIterate()
    {
        if(head == null || head.next == null)
            return;

        Node prevNode = head;
        Node currNode = head.next;
        while(currNode != null)
        {
            Node nextNode = currNode.next;
            currNode.next = prevNode;

            prevNode = currNode;
            currNode = nextNode;
        }
        head.next = null;
        head = prevNode;

    }





    public static void main(String args[])
    {
        LL list = new LL();
        list.addFirst("a");
        list.addFirst("is");
        list.printList();
        list.addLast("Linked List");
        list.addFirst("This");
        list.printList();
        list.deleteLast();
        list.printList();
        System.out.println(list.getSize());
        list.reverseIterate();
        list.printList();

    }
}
