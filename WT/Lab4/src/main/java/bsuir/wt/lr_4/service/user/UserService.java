package bsuir.wt.lr_4.service.user;

import bsuir.wt.lr_4.model.User;

import java.util.HashMap;

public interface UserService {

    void saveNewUser(HashMap<String, String> registrationData);

    User findUserByAuthData(String email, String passworo);
}
