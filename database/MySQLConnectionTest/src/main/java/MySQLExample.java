import java.sql.*;
public class MySQLExample {
    private Connection connect = null;

    public MySQLExample(String user, String password) throws Exception{
        try{

            String server = "cs3743.fulgentcorp.com";  // change with data received in email
            String db = "ab_mgomez"; // change with data received in email
            String url = "jdbc:mysql://" + server + "/" + db;
            // this will load the MySQL driver, each DBMS has its own driver
            Class.forName("com.mysql.jdbc.Driver");
            this.connect = DriverManager.getConnection(url
                    , user
                    , password);
        }
        catch (Exception e){
            throw e;
        }
    }


    public void runProgram() {
        try {
            Statement myStmt = connect.createStatement();
            String sql = "select * from Student";
            ResultSet rs = myStmt.executeQuery(sql);

            while (rs.next())
                System.out.println(rs.getString("studentNr"));

        } catch (SQLException throwables){
            throwables.printStackTrace();
        }
    }

    public void close() throws SQLException {
        connect.close();
    }
}
