#ifndef MYCLASS_H
#define MYCLASS_H
class myclass
{
   private:
	static int s_num;
   public:
        myclass();
	~myclass();
	static int get_num(); 

};
#endif
