import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/DisplayBooks")
public class DisplayBooksServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        // JDBC URL, username, and password of MySQL server
        String jdbcURL = "jdbc:mysql://localhost:3306/mydatabase";
        String dbUser = "root";
        String dbPassword = "password";

        try {
            // Load MySQL JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Create a connection to the database
            Connection connection = DriverManager.getConnection(jdbcURL, dbUser, dbPassword);

            // Create a statement
            Statement statement = connection.createStatement();

            // Execute a query
            ResultSet resultSet = statement.executeQuery("SELECT * FROM ebookshop");

            // Display result set as HTML table
            out.println("<html><body>");
            out.println("<h1>Book Inventory</h1>");
            out.println("<table border=\"1\">");
            out.println("<tr><th>Book ID</th><th>Title</th><th>Author</th><th>Price</th><th>Quantity</th></tr>");
            while (resultSet.next()) {
                out.println("<tr>");
                out.println("<td>" + resultSet.getInt("book_id") + "</td>");
                out.println("<td>" + resultSet.getString("book_title") + "</td>");
                out.println("<td>" + resultSet.getString("book_author") + "</td>");
                out.println("<td>" + resultSet.getDouble("book_price") + "</td>");
                out.println("<td>" + resultSet.getInt("quantity") + "</td>");
                out.println("</tr>");
            }
            out.println("</table>");
            out.println("</body></html>");

            // Close all connections
            resultSet.close();
            statement.close();
            connection.close();
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }
}
