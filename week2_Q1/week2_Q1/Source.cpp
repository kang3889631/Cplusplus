void func(int x1, int x2 = 2, int x3 = 3) {}

func(10); //equal to func(10,2,3)
func(10, 8); //equal to func(10,8,3)
func(10, , 8); //error. Only continuous right side parameters missing 