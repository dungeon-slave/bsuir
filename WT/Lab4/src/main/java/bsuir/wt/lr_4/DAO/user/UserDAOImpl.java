package bsuir.wt.lr_4.DAO.user;

import bsuir.wt.lr_4.model.Role;
import bsuir.wt.lr_4.model.User;
import bsuir.wt.lr_4.util.DataSourceConnection;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDAOImpl implements UserDAO {

    @Override
    public boolean saveNewUser(User user) {
        try (Connection connection = DataSourceConnection.getConnectionPool().getConnection()) {
            PreparedStatement checkIfEmailAlreadyExistQuery = connection.prepareStatement(
                    "SELECT * FROM users WHERE email = ?"
            );
            checkIfEmailAlreadyExistQuery.setString(1, user.getEmail());
            ResultSet resultSet = checkIfEmailAlreadyExistQuery.executeQuery();

            //if user with email = user.getEmail() doesn't exist -> add new
            if(resultSet.next() == false) {
                PreparedStatement saveNewUserQuery = connection.prepareStatement(
                        "INSERT INTO users (name, surname, email, password) " +
                            "VALUES (?, ?, ?, ?) RETURNING user_id"
                );
                saveNewUserQuery.setString(1, user.getName());
                saveNewUserQuery.setString(2, user.getSurname());
                saveNewUserQuery.setString(3, user.getEmail());
                saveNewUserQuery.setString(4, user.getPassword());
                ResultSet returnedId = saveNewUserQuery.executeQuery();

                if(returnedId.next()){
                }
                final long generatedUserId = returnedId.getLong("user_id");
                PreparedStatement giveRoleToUserQuery = connection.prepareStatement(
                        "INSERT INTO user_role (user_id, role_id) VALUES " +
                                "(?, (SELECT role_id FROM role WHERE role_name = ?))"
                );
                giveRoleToUserQuery.setLong(1, generatedUserId);
                giveRoleToUserQuery.setString(2, Role.ROLE_USER.toString());
                giveRoleToUserQuery.execute();
                return true;
            }
            return false;
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

    @Override
    public User findUserByEmail(String email) {
        try (Connection connection = DataSourceConnection.getConnectionPool().getConnection()) {
            PreparedStatement findUserByEmailQuery = connection.prepareStatement(
                    "SELECT user_id, name, surname, email, password, role.role_name\n" +
                            "FROM users\n" +
                            "JOIN role ON role.role_id = user_id\n" +
                            "WHERE email = ?;"
            );
            findUserByEmailQuery.setString(1, email);
            ResultSet resultSet = findUserByEmailQuery.executeQuery();

            if(resultSet.next() == true) {
                return User.builder()
                        .id(resultSet.getLong("user_id"))
                        .name(resultSet.getString("name"))
                        .surname(resultSet.getString("surname"))
                        .email(resultSet.getString("email"))
                        .password(resultSet.getString("password"))
                        .role(Role.valueOf(resultSet.getString("role_name")))
                        .build();
            }
            return null;
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }
}
