
1.	Inventory Management System
Operations
1.	Insert a record
2.	Edit a record
3.	Delete a record
4.	View

        ITEM FILE

1	Item Code	it_code	Int
2	Item Name	it_name	Char[20]
3	Item Price	it_price	int
4	Opening Stock	it_os	Int
5	Closing Stock	It_cs	int


    PURCHASE FILE

1	Purchase Number	p_no	Int
2	Purchase Date	p_date	Char[20]
3	Client code	c_code	int
4	Client Name	c_name	Char[20]
5	Product Code	p_code	Int
6	Purchase Quantity	p_qty	int
7	Purchase Price	p_price	int
8	Purchase Amount	p_amt	int

    SALES FILE

1	Bill Number	b_no	Int
2	Bill Date	b_date	Char[10]
3	Product Code	p_code	int
4	Quantity	b_qty	int
5	Rate	b_rate	Int
6	Tax	b_tax	int
7	Amount	b_amt	int

