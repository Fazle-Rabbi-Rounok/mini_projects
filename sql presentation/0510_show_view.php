<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="stylesheet" href="cs.css" />
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>View Example</title>
    <style>
        .to {
            text-align: center;
            /* Centers text inside the box */
            color: rgb(0, 0, 0);
            font-size: 50px;
            font-family: "Georgia", serif;
            max-width: 250px;
            /* Limits the width of the box */
            padding: 14px;
            /* Adds space inside the box */
            background: bisque;
            /* White background */
            border-radius: 10px;
            /* Rounds the corners */
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);
            /* Adds shadow for depth */
            border: 2px solid rgb(7, 1, 0);
            /* Red border */
            margin: 0 auto 50px auto;
        }
    </style>
</head>

<body>
    <div>
        <p class="to">Show View</p>
    </div>
    <!-- Left-aligned content: Definition -->
    <div class="left-container">
        <p><b>Definition</b></p>
    </div>
    <p class="defination">
        A view in SQL is a virtual table created based on the result of a SELECT
        query. It does not store data itself but provides a way to simplify
        complex queries or improve security by restricting access to certain
        columns or rows
    </p>
    <!-- Left-aligned content: Code -->
    <div class="left-container">
        <p><b>Code</b></p>
    </div>
    <div>
        <pre class="code-box">
SELECT
        *
    FROM
        user_orders_view;</pre>
    </div>

    <?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "shopping";
    $port = 3307;

    $conn = new mysqli($servername, $username, $password, $dbname, $port);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $sql = "SELECT * FROM user_orders_view";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        echo "<table>
                <tr> 
                    <th>Name</th>
                    <th>Email</th>
                    <th>Product</th>
                    <th>Amount</th>
                </tr>";
        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>{$row['name']}</td>
                    <td>{$row['email']}</td>
                    <td>{$row['product']}</td>
                    <td>{$row['amount']}</td>
                </tr>";
        }
        echo "</table>";
    } else {
        echo "No data found.";
    }

    $conn->close();
    ?><a href="http://localhost/exp/05_queries.html" class="go-home">Home</a>
</body>

</html>