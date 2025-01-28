<!DOCTYPE html>
<html lang="en">

<head>
    <style>
        .to {
            text-align: center;
            color: rgb(0, 0, 0);
            font-size: 50px;
            font-family: "Georgia", serif;
            max-width: 240px;
            padding: 14px;
            background: bisque;
            border-radius: 10px;
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);
            border: 2px solid rgb(7, 1, 0);
            margin: 0 auto 50px auto;
        }

        .left-container {
            text-align: left;
            margin-bottom: 20px;
        }

        .defination {
            text-align: left;
            margin-bottom: 20px;
        }

        .code-box {
            background: #f4f4f4;
            padding: 10px;
            border-radius: 5px;
            border: 1px solid #ccc;
            font-family: monospace;
            white-space: pre-wrap;
            text-align: left;
        }

        .butt {
            background: #4caf50;
            color: white;
            padding: 10px 20px;
            text-decoration: none;
            border-radius: 5px;
            display: inline-block;
        }

        .diagram {
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 20px;
        }

        .diagram img {
            max-width: 45%;
            height: auto;
        }

        .diagram-text {
            max-width: 50%;
        }
    </style>
    <link rel="stylesheet" href="cs.css" />
    <title>Document</title>
</head>

<body>
    <div>
        <p class="to">Inner Join</p>
    </div>

    <!-- Diagram and Definition -->
    <div class="diagram">
        <div class="diagram-text">
            <div class="left-container">
                <p><b>Definition</b></p>
            </div>
            <p class="defination">
                The INNER JOIN clause in SQL is used to retrieve records from two or more
                tables that have matching values in the specified columns. It combines
                rows from both tables when the join condition is true.
            </p>
        </div>
        <img src="inner.jpg" alt="Inner Join Diagram" width="400">
    </div>

    <!-- Left-aligned content: Code -->
    <div class="left-container">
        <p><b>Code</b></p>
    </div>
    <div>
        <pre class="code-box">
SELECT
    users.id,
    users.name,
    orders.product,
    orders.amount
FROM
    users
    INNER JOIN orders ON users.id = orders.user_id;</pre>
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

    $sql = "SELECT users.id,users.name, orders.product, orders.amount 
            FROM users 
            INNER JOIN orders ON users.id = orders.user_id";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        echo "<table>
                <tr>
                    <th>User ID</th>
                    <th>User Name</th>
                    <th>Product</th>
                    <th>Amount</th>
                </tr>";
        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>{$row['id']}</td>
                    <td>{$row['name']}</td>
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