#include <STC89C5xRC.H>
#define SW1 P42	//����SW1 ����
#define SW2 P43	//����SW2 ����

//���󣺶�����������LED�Ƶ��ƶ�
//��ʱ����������->��������
void Delay10ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 18;
	j = 235;
	do
	{
		while (--j);
	} while (--i);
}

void main()
{
	unsigned char i = 0;   // �ֲ�����Ҫ������ʼֵ�������������i
	P0 = ~0x01;
	while (1)
	{
		if (SW1 == 0)      		// ��鰴��SW1
		{
			Delay10ms();   			// ��ʱ����
			while (SW1 == 0);  // �ȴ������ͷ�
			Delay10ms();       // ��ʱ����
				
			i++;
			if(i>=8)
				i=0;
			
			P0 = ~(0x01<<i);		
			}
		
		if(SW2 == 0)
		{
			Delay10ms();
			while(SW2 == 0);
			Delay10ms();
			
			if(i==0)
				i = 7;
			else
				i--;
			P0 = ~(0x01<<i); //��������������iλ��������1λ���൱������7λ
			//����i=3.��ʱ���ĸ�LED��������1λ����ʱi = 2������������
		}
		}
}

