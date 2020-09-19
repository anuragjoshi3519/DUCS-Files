class Account{
    String name;
    String account_num;
    String account_type;
    double balance;

    public void deposit(double amount){
        balance+=amount;
        System.out.println("Amount successfully credited to your account.");
        display_balance();
    }

    public void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            System.out.println("Amount successfully debited from your account.");
            display_balance();
        }
        else{
            System.out.println("Your account balance is not enough to make that withdrawal.");
        }
    }

    public void display_balance(){
        System.out.println("Your account balance: Rs. "+balance+" /-");
    }

    public void account_info(){
        System.out.println("Name: "+name);
        System.out.println("Account Type: "+account_type);
        System.out.println("Account Number: "+account_num);
        System.out.println("Account Balance: Rs."+balance+"/-");
    }
}

class Curr_acct extends Account{
    int min_balance = 1000;
    int min_balance_penalty = 100;

    public void initialize_members(String name,String account_num, double balance){
        this.name = name;
        this.account_num = account_num;
        this.balance = balance;
        this.account_type= "current";
    }
    public void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            System.out.println("Amount successfully debited from your account.");
            display_balance();
            check_min_balance();
        }
        else{
            System.out.println("Your account balance is not enough to make that withdrawal.");
        }
    }

    public void check_min_balance(){
        if(balance<min_balance){
            System.out.println("Your balance is lesser than minimum required balance.");
            impose_penalty();
        }else{
            System.out.println("Your balance is more than minimum required balance.");
        }
    }

    public void impose_penalty(){
        if(balance>=100){
            balance-=100;
        }else{
            balance = 0;
        }
        System.out.println("Penalty imposed.");
        display_balance();
    }

}

class Sav_acct extends Account{
    double interest_rate = 0.07; // 7% interest rate
    double interest = 0;

    public void initialize_members(String name,String account_num, double balance){
        this.name = name;
        this.account_num = account_num;
        this.balance = balance;
        this.account_type= "savings";
    }

    public void compute_interest(){              // compound interest (compounded yearly)
        interest = balance*(1 + interest_rate) - balance;
        System.out.println("Interest is Rs."+interest+"/-");
    }

    public void deposit_interest(){
        balance+=interest;
        interest=0;
        System.out.println("Interest deposited.");
        display_balance();
        
    }
}

class BankClass{
    public static void main(String args[]){
        Sav_acct acc1= new Sav_acct();
        Curr_acct acc2=new Curr_acct();
    
        acc1.initialize_members("Ratan Tata","1700908934537876", 100000);
        acc2.initialize_members("Sunder Pichai","7600302034578392", 50000);

        acc1.account_info();
        acc1.deposit(1000);
        acc1.withdraw(2000);
        acc1.compute_interest();
        acc1.deposit_interest();

        System.out.println("\n");

        acc2.account_info();
        acc2.deposit(10000);
        acc2.withdraw(59500);
        acc2.check_min_balance();
    }

}
