import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/transactions")
public class TransactionServlet extends HttpServlet {

    @EJB
    private BankService bankService;

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String action = request.getParameter("action");
        String accountNumber = request.getParameter("accountNumber");
        double amount = Double.parseDouble(request.getParameter("amount"));

        if (action.equals("deposit")) {
            bankService.deposit(accountNumber, amount);
        } else if (action.equals("withdraw")) {
            bankService.withdraw(accountNumber, amount);
        }

        response.sendRedirect("transaction-success.jsp");
    }
}
