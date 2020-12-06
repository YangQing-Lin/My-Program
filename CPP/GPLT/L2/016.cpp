#include<bits/stdc++.h>
using namespace std;

struct node {
    int id, fatherid, motherid;
    char sex;
};

// unordered_set<int> fir, sec;
// int count;
// void find_fir(node temp) {
//     fir.insert(temp.fatherid);
//     fir.insert(temp.motherid);
//     find_fir(book[temp.fatherid]);
//     find_fir(book[temp.motherid]);
// }

void clear(queue<int>& q) {
	queue<int> empty;
	swap(empty, q);
}

int main() {
    int n, a, b, c;
    node temp, temp1, temp2;
    temp = {-1, 'F', -1, -1};
    vector<node> book(100005, temp);
    queue<int> fir, sec;
    queue<int> empty_queue;
    char ch;
    cin >> n;
    while(n--) {
        cin >> temp.id >> temp.sex >> temp.fatherid >> temp.motherid;
        book[temp.id] = temp;
    }
    cin >> n;
    while(n--) {
        cin >> a >> b;
        if (book[a].sex == book[b].sex) {
            printf("Never Mind\n");
        } else {
            bool flag = false;
            set<int> l1, l2, l3, l4;
            l1.insert(a);
            l3.insert(b);
            for(int i = 0; i < 4; i++) {
                for(auto it = l1.begin(); it != l1.end(); it++) {
                    if(book[*it].fatherid != -1) l2.insert(book[*it].fatherid);
                    if(book[*it].motherid != -1) l2.insert(book[*it].motherid);
                }
                for(auto it = l3.begin(); it != l3.end(); it++) {
                    if(book[*it].id != -1 && l2.find(book[*it].fatherid) != l2.end()) {
                        flag = true;
                        // printf("$%d %d %d$\n", *it,book[*it].id , book[*it].fatherid);
                    }
                    if(book[*it].id != -1 && l2.find(book[*it].motherid) != l2.end()) {
                        flag = true;
                        // printf("^%d %d %d^\n", *it, book[*it].id, book[*it].motherid);
                    }
                    if(flag) break;
                    if(book[*it].fatherid != -1) l4.insert(book[*it].fatherid);
                    if(book[*it].motherid != -1) l4.insert(book[*it].motherid);
                }
                if(flag) break;
                l1 = l2;
                l2.clear();
                l3 = l4;
                l4.clear();
            }
            if(flag) printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}