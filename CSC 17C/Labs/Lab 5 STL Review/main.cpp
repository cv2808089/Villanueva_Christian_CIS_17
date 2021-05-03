#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include<stack>
using namespace std;


int main() 
{
    //pairs
    cout << "Two values being stored in a pair" << endl;
    pair<int, float> p1;
    p1.first = 1;
    p1.second = 2.01;
    
    cout << p1.first << endl;
    cout << p1.second << endl;
    cout << endl << endl;
    
    
    
    //vectors
    cout << "vector holding 1, 2, and 4" << endl;
    vector<int> v1;
    v1 = {1, 2, 4};
    vector<int>::iterator iv;
    for(iv = v1.begin(); iv != v1.end(); iv++)
        cout << *iv << ' ';
    cout << endl;
    
    cout << "Popping the 4 off the back and pushing on a 3" << endl;
    v1.pop_back();
    v1.push_back(3);
    for(iv = v1.begin(); iv != v1.end(); iv++)
        cout << *iv << ' ';
    cout << endl << endl << endl;
    
    
    
    //lists
    cout << "Linked List pushing on values 2, 3, 4, 5 one at a time to the back" << endl;
    list<int> li;
    for(int i = 0; i < 4; i++)
        li.push_back(i+2);
    list<int> :: iterator il;
    for(il = li.begin(); il != li.end(); il++)
    {
        cout << *il << ' ';
    }
    cout << endl;
    
    cout << "Pushing 1 onto the front" << endl;
    li.push_front(1);
    for(il = li.begin(); il != li.end(); il++)
    {
        cout << *il << ' ';
    }
    cout << endl;
    
    cout << "Inserting 7 into the third position and pushing the others back" <<endl;
    advance(il, 3);
    li.insert(il, 7);
    for(il = li.begin(); il != li.end(); il++)
    {
        cout << *il << ' ';
    }
    cout << endl;
    
    cout << "Deleting the second position, and moving the other values froward" << endl;
    advance(il, 2);
    li.erase(il);
    for(il = li.begin(); il != li.end(); il++)
    {
        cout << *il << ' ';
    }
    cout << endl << endl << endl;
    
    
    
    //stacks
    cout << "stack of aces (pushed in order: spades, clubs, diamonds, hearts)" << endl;
    stack<string> s1;
    s1.push("ace of spades");
    s1.push("ace of clubs");
    s1.push("ace of diamonds");
    s1.push("ace of hearts");
    
    cout << "Show top of stack" << endl;
    cout << s1.top() << endl;
    
    cout << "Remove top of stack and show next element" << endl;
    s1.pop();
    cout << s1.top();
    cout << endl << endl << endl;
    
    
    
    //queues
    cout << "Creating a queue with four people, in order: 1, 2, 3, 4" << endl;
    queue<string> q1;
    q1.push("Person 1");
    q1.push("Person 2");
    q1.push("Person 3");
    q1.push("Person 4");
    
    cout << "Queue size is " << q1.size() << endl;
    cout << "Front of the queue is: " << q1.front() << endl;
    q1.pop();
    cout << "Front of queue after popping off the previous front: " << q1.front() << endl;
    cout << endl << endl;
    
    
    
    
    //sets
    cout << "Creating a set wiht values inserted in order: 1.25, .25, 3.75, 5.0(set is initialized to be greatest to least)" << endl;
    set<float, greater<float> > se;
    se.insert(1.25);
    se.insert(.25);
    se.insert(3.75);
    se.insert(5.0);
    
    set<float, greater<float> >:: iterator is;
    for(is = se.begin(); is != se.end(); is++)
        cout << *is << ' ';
    cout << endl;
    
    cout << "Inserting 1.25, .05, and 7" << endl;
    se.insert(1.25);
    se.insert(.05);
    se.insert(7);
    for(is = se.begin(); is != se.end(); is++)
        cout << *is << ' ';
    cout << endl << endl << endl;
    
    
    
    
    //maps
    cout << "Creating a map with keys 1-10, and values 10-100" << endl;
    map<int, int> m1;
    for(int i = 1; i <= 10; i++)
        m1.insert(pair<int, int>(i, i*10));
    map<int, int>::iterator im;
    for(im = m1.begin(); im != m1.end(); im++)
        cout << im->first << ' ' << im->second << endl;
    cout << endl;
    
    cout << "Erasing elements with keys less than 4" << endl;
    m1.erase(m1.begin(), m1.find(4));
    for(im = m1.begin(); im != m1.end(); im++)
        cout << im->first << ' ' << im->second << endl;
    cout << endl << endl;
    
    
    
    //shuffle
    cout << "Before shuffle: " << endl;
    string c1[] = {"ace", "jack", "king", "ten"};
    for(int i = 0; i < 4; i++)
        cout << c1[i] << ' ';
    cout << endl;
    
    cout << "After shuffle: " << endl;
    random_shuffle(c1, c1+4);
    for(int i = 0; i < 4; i++)
        cout << c1[i] << ' ';
    cout << endl << endl << endl;
    
    
    
    
    //sort
    cout << "The list from earlier sorted from least to greatest" << endl;
    li.sort();
    for(il = li.begin(); il != li.end(); il++)
    {
        cout << *il << ' ';
    }
    cout << endl << endl << endl;
    
    
    
    //find
    cout << "searching for 2 in the vector" << endl;
    for(iv = v1.begin(); iv != v1.end(); iv++)
        cout << *iv << ' ';
    cout << endl;
    iv = find(v1.begin(), v1.end(), 2);
    cout << "2 found at position: " << iv - v1.begin() << endl;
    cout << endl << endl;
    
    
    
    //min & max
    cout << "The min value of the list is: " << *min_element(li.begin(), li.end()) << endl;
    cout << "The max value of the list is: " << *max_element(li.begin(), li.end()) << endl;
    return 0;
}