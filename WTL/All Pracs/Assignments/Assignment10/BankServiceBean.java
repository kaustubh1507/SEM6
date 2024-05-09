import javax.ejb.Stateless;

@Stateless
public class BankServiceBean implements BankService {

    @Override
    public void deposit(String accountNumber, double amount) {
        // Implement deposit logic here
    }

    @Override
    public void withdraw(String accountNumber, double amount) {
        // Implement withdraw logic here
    }
}
