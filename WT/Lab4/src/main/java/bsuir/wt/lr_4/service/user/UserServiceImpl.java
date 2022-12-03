package bsuir.wt.lr_4.service.user;

import bsuir.wt.lr_4.DAO.user.UserDAO;
import bsuir.wt.lr_4.model.Role;
import bsuir.wt.lr_4.model.User;

import java.util.HashMap;

public class UserServiceImpl implements UserService {

    private final UserDAO userDAO;

    public UserServiceImpl(UserDAO userDAO) {
        this.userDAO = userDAO;
    }

    @Override
    public void saveNewUser(HashMap<String, String> registrationData) {
        User newUser = User.builder()
                .name(registrationData.get("name"))
                .surname(registrationData.get("surname"))
                .email(registrationData.get("email"))
                .password(registrationData.get("password"))
                .role(Role.ROLE_USER)
                .build();
        userDAO.saveNewUser(newUser);
    }

    @Override
    public User findUserByAuthData(String email, String password) {
        User user = userDAO.findUserByEmail(email);
        if (user.getPassword().equals(password)) {
            return user;
        }
        return null;
    }
}
