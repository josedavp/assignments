import java.sql.*;

public class P3Program
{
    private Connection connect = null;
    private Statement statement = null;
    private PreparedStatement preparedStatement = null;
    private ResultSet resultSet = null;
    public static final int ER_DUP_ENTRY = 1062;
    public static final int ER_DUP_ENTRY_WITH_KEY_NAME = 1586;
    public static final String[] strPropertyIdM =
            {   "MTNDDD"
                    ,"NYCCC"
                    ,"HOMEJJJ"
                    ,"END"
            };

    public P3Program (String server, String database, String user, String password) throws Exception
    {
        String port = "3306";

        String url = "jdbc:mysql://" + server + ":" + port + "/" + database;

        try
        {
            // This will load the MySQL driver, each DBMS has its own driver
            connect  = DriverManager.getConnection(url, user, password);
            connect.setTransactionIsolation(Connection.TRANSACTION_READ_COMMITTED);

        }
        catch (Exception e)
        {
            throw e;
        }

    }

    public void runProgram() throws Exception
    {

        // Code the #3 functionalities that start in page 5 of the problem statement

        // functionality 3.a
        statement = connect.createStatement();
        resultSet = statement.executeQuery("select c.* from Customer c;");

        printCustomers("Beginning Customers", resultSet);

        // functionality 3.b
        statement = connect.createStatement();
        resultSet = statement.executeQuery("select m.* from Property m;");
        MySqlUtility.printUtility("Beginning Properties", resultSet);

        // functionality 3.c
        try {
            statement.executeUpdate("INSERT INTO Customer (custNr, name, baseLoc, birthDt, gender) VALUES (1999, \"Jose_Pague\", \"TX\", 1997, \"Male\");");
        }
        catch (Exception e)
        {
            System.out.println("Error runProgram\n" + e);
        }

        // functionality 3.d
        statement = connect.createStatement();
        resultSet = statement.executeQuery("select c.* from customer c;");

        printCustomers("Customers after I was added", resultSet);

        // functionality 3.e
        statement = connect.createStatement();
        resultSet = statement.executeQuery("select TABLE_SCHEMA, TABLE_NAME, INDEX_NAME" +
                ", SEQ_IN_INDEX, COLUMN_NAME, CARDINALITY " +
                "from INFORMATION_SCHEMA.STATISTICS " +
                "where TABLE_SCHEMA = \"cs3743_vib296\" " +
                "and TABLE_NAME = \"Rental\" " +
                "order by INDEX_NAME, SEQ_IN_INDEX; ");
        MySqlUtility.printUtility("My Rental Indexes", resultSet);

        // functionality 3.f
        preparedStatement = connect.prepareStatement("INSERT INTO Rental (custNr, propId, startDt, totalCost) VALUES (?, ?, ?, ?);" );

        // functionality 3.g
        for (int i = 0; i < strPropertyIdM.length && !strPropertyIdM[i].equals("END"); i++)
        {
            preparedStatement.setInt(1, 1999);
            preparedStatement.setString(2, strPropertyIdM[i]);
            preparedStatement.setDate(3, Date.valueOf("2019-12-14"));
            preparedStatement.setDouble(4, 200.00 + (10.00 * i));
            try {
                preparedStatement.executeUpdate();
            }
            catch (SQLException e) {
                switch (e.getErrorCode()) {
                    case ER_DUP_ENTRY:
                    case ER_DUP_ENTRY_WITH_KEY_NAME:
                        System.out.printf("Duplicate key error: %s\n", e.getMessage());
                        break;
                    default:
                        throw e;
                }
            }
            catch (Exception e)
            {
                throw e;
            }
        }

        // functionality 3.h
        preparedStatement = connect.prepareStatement("select * Rental where Rental.custNr= ?;");
        preparedStatement.setInt(1, 1999);
        resultSet = preparedStatement.executeQuery();
        MySqlUtility.printUtility("My rentals", resultSet);

        // functionality 3.i
        statement = connect.createStatement();
        resultSet = statement.executeQuery("select r.propId, c.custNr, c.name, r.totalCost \n" +
                "from Customer c, Rental r\n" +
                "where r.custNr = c.custNr and c.custNr != 1999 \n" +
                "and Exists (\n" +
                "select * \n" +
                "from Rental r1\n" +
                "where r1.custNr = 1999\n" +
                "and r1.propId = r.propId);");

        MySqlUtility.printUtility("Other customers renting my properties", resultSet);

        // functionality 3.j
        statement = connect.createStatement();
        statement.executeUpdate("UPDATE Rental set totalCost = 0.90 * totalCost;");

        // functionality 3.k
        preparedStatement = connect.prepareStatement("select * Rental where Rental.custNr= ?;");
        preparedStatement.setInt(1, 1999);
        resultSet = preparedStatement.executeQuery();
        MySqlUtility.printUtility("My Cheaper Rentals", resultSet);

        // functionality 3.l
        statement = connect.createStatement();
                            //NOT SURE HERE----------------------------------->
        resultSet = statement.executeQuery("select r.propId , COUNT(*) from Rental r group by r.propId having COUNT(*) > 1;");
        MySqlUtility.printUtility("", resultSet); //SHOULD THIS BE BLANK FOR ""???

        // functionality 3.m
        statement = connect.createStatement();
                            //NOT SURE HERE IS IT CORRECT??----------------------------------->
        statement.executeUpdate("DELETE FROM Rental r where r.custNr = 1999;");

        // functionality 3.n
        statement = connect.createStatement();
        resultSet = statement.executeQuery("select r.propId, c.custNr, c.name, r.totalCost \n" +
                "from Customer c, Rental r\n" +
                "where r.custNr = c.custNr and c.custNr != 1999 \n" +
                "and Exists (\n" +
                "select * \n" +
                "from Rental r1\n" +
                "where r1.custNr = 1999\n" +
                "and r1.propId = r.propId);");
        MySqlUtility.printUtility("Other customers renting my properties after my rentals were deleted", resultSet);
        // Remember to close the statement and connect(ion)
    }

    private void printCustomers(String title, ResultSet resultSet) throws SQLException
    {
        // Your output for this must match the format of my sample output exactly.
        // custNr, name, baseLoc, birthDt, gender

        // your code
        System.out.printf("%s\n", title);
        System.out.printf("%4d, %7s %7s %7s %7s ", "custNr", "name", "baseLoc", "birthDt", "gender" );

        while (resultSet.next())
        {
            int custNrNum = resultSet.getInt("custNr");

            String nameStr = resultSet.getString("name");
            String baseLocStr = resultSet.getString("baseLoc");

            Date birthDtNum = resultSet.getDate("birthDt");
            String birthDtTemp;

            String genderStr = resultSet.getString("gender");

            if (nameStr == null)
            {
                nameStr = "---";
            }
            if (baseLocStr == null)
            {
                baseLocStr = "---";
            }
            if (genderStr == null)
            {
                genderStr = "---";
            }
            if(birthDtNum == null)
            {
                birthDtTemp = "---";
            }
            else
            {
                birthDtTemp = birthDtNum.toString();
            }
            System.out.printf("%4d, %7s %7s %7s %7s\n", custNrNum, nameStr,  baseLocStr, birthDtTemp, genderStr);
            System.out.printf("\n"); //do we need to check if no rows are found? with example 10 or is this good as is?
        }
        // remember to close your resultSet
    }

}
