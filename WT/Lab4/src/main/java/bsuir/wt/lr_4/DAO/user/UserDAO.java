package bsuir.wt.lr_4.DAO.user;

import bsuir.wt.lr_4.model.User;

public interface UserDAO {

    boolean saveNewUser(User user);

    User findUserByEmail(String email);
}
