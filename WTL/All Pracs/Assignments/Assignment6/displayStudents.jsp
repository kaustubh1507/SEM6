<%@ page import="java.sql.*" %>
<html>
<head>
    <title>Display Students</title>
</head>
<body>

<h2>Student Information</h2>

<table border="1">
<tr>
    <th>Student ID</th>
    <th>Name</th>
    <th>Class</th>
    <th>Division</th>
    <th>City</th>
</tr>

<%
    // Database connection details
    String url = "jdbc:mysql://localhost:3306/school";
    String user = "your_username";
    String password = "your_password";
    
    // JDBC variables
    Connection conn = null;
    Statement stmt = null;
    ResultSet rs = null;

    try {
        // Establishing connection
        Class.forName("com.mysql.jdbc.Driver");
        conn = DriverManager.getConnection(url, user, password);
        
        // Creating SQL statement
        stmt = conn.createStatement();
        String sql = "SELECT * FROM students_info";
        
        // Executing query
        rs = stmt.executeQuery(sql);
        
        // Displaying result set
        while (rs.next()) {
            out.println("<tr>");
            out.println("<td>" + rs.getInt("stud_id") + "</td>");
            out.println("<td>" + rs.getString("stud_name") + "</td>");
            out.println("<td>" + rs.getString("class") + "</td>");
            out.println("<td>" + rs.getString("division") + "</td>");
            out.println("<td>" + rs.getString("city") + "</td>");
            out.println("</tr>");
        }
    } catch (Exception e) {
        e.printStackTrace();
    } finally {
        // Closing resources
        try {
            if (rs != null) rs.close();
            if (stmt != null) stmt.close();
            if (conn != null) conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
%>

</table>

</body>
</html>
