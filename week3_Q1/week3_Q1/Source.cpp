class Test {
public:
	Test(int n) {}       //1
	Test(int n,int m){}  //2
	Test(){}             //3
};
Test array1[3] = { 1,Test(1,2) }; //1,2,3
Test array2[3] = { Test(2,3),Test(1,2),1 }; //2,2,1
Test *pArray[3] = { new Test(4),new Test(1,2) };//1,2