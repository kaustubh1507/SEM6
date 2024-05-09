<%@ taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Login Page</title>
    <style>
        .error {
            color: red;
        }
    </style>
</head>
<body>
    <h2>Login</h2>
    <s:form action="login" method="post">
        <s:textfield key="name" label="Name"/>
        <s:textfield key="mobile" label="Mobile Number"/>
        <s:textfield key="email" label="Email"/>
        <s:submit value="Login"/>
    </s:form>
    <s:if test="hasActionErrors()">
        <div class="error">
            <s:actionerror/>
        </div>
    </s:if>
</body>
</html>
