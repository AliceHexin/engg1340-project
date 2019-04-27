# engg1340-project
Nowadays, people living in hustling cities usually have a busy life with little time for consumption records and property settlement. Meanwhile, the development of online shopping makes it easier to consume some useless goods impulsively. Therefore, many people may lack a correct understanding of their shopping habits and financial situation.
In this project, we would like to design an accounting system to help people manage their wealth smartly. The system will contain following functions:
1. Add records of income and expenses.(Up to 10 users can be created, which means 10 peaple can use this system at the same time with different user's names.);

2. The records would contain some basic information, like amount, date, types of income or expense (e.g. food, game, salary, etc. The maximum number of types that can be created is 50), account (e.g. cash, bank card, credit card, etc. The maximum number of accounts that can be created is 20);

3. The records could be deleted or edited at any time;

4. Users could view their records by date, type, and account;

5. The system provides a statistical report of users’ financial state (e.g. monthly income and expenses, percentage of food expenses, etc.);

6. The accounting system allows budget setting. When expenses reach the budget, there should be an alert.

7. "Wonderlist" function: users could set a target amount of deposit and clarify the aim of it (e.g. $10000 for an overseas trip), when the deposit reaches the target number, there would be a notice.

# user guide:

## 1.1 get into the system

input "enter" to enter the system or "quit" to exit, then enter your name to login.
the menu will show you what commands you could input, untill you enter "quit", you can input another coammand once you finish one  

sample：

```
Do you want to enter your accounting system or quit? enter  

Please input your name: ma

Hello ma, your accounting system has been built!

structure:
quit: exit the system
add: add your accounting record
delete: delete your accounting record
edit: edit your accounting record
view: view your accounting record
stat: show the summary of your record
budget: set a budget
wonderlist: set a target amount of income

Please input your request:  
```

## 2.1 add record

input command "add" to append record, input the date(yyyymmdd), amount, type(food,game,salary etc.), and account(cash, creditcard).
the record you enter would be save in yourname_date.txt(e.g. ma_date.txt...), yourname_type.txt(e.g. ma_food.txt...),yourname_account.txt(e.g. ma_cash.txt...)...
after finishing adding record, you could input next command.

**reminder:**
no space when input.
enter records in chronological order.
when entering amount, the amount of expense should be negative(e.g.: -100),only number is allowed .
when entering the date, try to fill the blank with 0 instead of space(e.g. 20110304),only number is allowed.
when entering type and account please make sure your input is correct in Capitalization.
all recrd in one type should be eighter negative or positive, (e.g when you have inputed  "20121212 -100 food  cash" do not input "20121112 20 food cash")


sample：

```
>Please input your request: add

date: 20120202 

amount: -100

type: food

account: cash

Your record has been added!

Please input your request: 
```
 
## 2.2 delete record

enter command "delete" to delete record, basically, the process of deleting record is similar with adding record;

sample:
```
Please input your request: delete

The date of the record to be deleted: 20120202

The amount of the record to be deleted: -100

The type of the record to be deleted: food

The account of the record to be deleted: cash

Your record has been deleted!
```

## 2.3 edit record

input "edit" to edit record, enter date,amount,type and account to search the record you would like to edit. then input all the information again to edit the record, basically, the information in old record will be replaced, by the information you input.

sample:
```
Please input your request: edit

The date of the record to be editted: 20121212

The amount of the record to be editted: 30

The type of the record to be editted: salary

The account of the record to be editted: cash

The date of the record editted: 20131212

The amount of the record editted: -10

The type of the record editted: food

The account of the record editted: card

Your record has been editted!

```

## 2.4 set budget

budget would be saved in file yournmae_budget.txt(e.g. ma_yourname.txt).
when add/delete/edit records, budget.cpp would be check if the difference of current expence is larger than budget, if yes, you will receive an alert. 

**reminder**
you could set 1 budget once, setting new budget will cover the origina one.

```
Please input your request: budget

set a budget over here10
Please input your request: add

date: 20101212

amount: -20

type: food

account: cash

Your record has been added!

***budget alert: expense achieved 10 now***

Please input your request: 
```
## 2.5 set wonderlist
input command "wonderlist" to add item and target amount of deposit , you could add at most 10 items, when you have enough money, the system would notice you.
the item and target amount would be saved in yourname_wonderlist.txt(e.g. ma_wonderlist.txt)
when target amount is achieved, you will received a message to notice you item is available now, the record in yourname_wonderlist.txt will be deleted.

** reminder**
do not set the items with the same name.

# 3 exit system from menu
input command "quit" twice would exit the system. 

```
Please input your request: quit

Do you want to enter your accounting system or quit? quit

Goodbye!
```
