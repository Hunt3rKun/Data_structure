
class stack						//ջ��
{
	public:
		stack(int m_size);
		~stack();
		void clearstack();		//���
		int isempty();			//�п�
		int length();			//�󳤶�
		char gettop();			//ȡջ��Ԫ��
		void push(char);			//��ջ
		int pop();			//��ջ
		void traverse();			//����
	protected:
		char *base;				//ջ��ָ��
		char *top;				//ջ��ָ��
		int size;				//ջ��С 
};
