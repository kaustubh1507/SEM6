import javax.ejb.Remote;

@Remote
public interface BankService {
    public void deposit(String accountNumber, double amount);
    public void withdraw(String accountNumber, double amount);
}
