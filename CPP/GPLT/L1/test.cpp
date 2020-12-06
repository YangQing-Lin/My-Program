#include <iostream>
using namespace std;
int main()
{
	string ans;   //s 
	int x;
	cin >> x;
	int r = 1;
	int cnt = 1;    //n 
	while(r < x){      //找到第一个大于等于x的光棍数 
		r = r * 10 + 1;
		cnt ++;
	}
	//模拟除法 
	while(r % x != 0){       //r可以整除x的时候退出 
		ans += r / x + '0';  //将r/x的值加入答案 
		r = r % x * 10 + 1;    //余数末尾加上一位1 
		cnt ++;              //位数+1 
	}
	ans += r / x + '0';  //最后整除的商加入答案 
	cout << ans << " " <<  cnt << endl;
	return 0; 
}
