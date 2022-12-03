package bsuir.wt.lr_4.servlet;

import bsuir.wt.lr_4.DAO.user.UserDAOImpl;
import bsuir.wt.lr_4.service.user.UserService;
import bsuir.wt.lr_4.service.user.UserServiceImpl;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;

@WebServlet(name = "registrationServlet", urlPatterns = "/registration")
public class RegistrationServlet extends HttpServlet {

    private static final String REGISTRATION_PAGE_JSP = "/WEB-INF/view/registrationPage.jsp";
    private static final String LOGIN_PAGE_JSP = "/WEB-INF/view/loginPage.jsp";

    private UserService userService;

    @Override
    public void init(ServletConfig config) throws ServletException {
        userService = new UserServiceImpl(new UserDAOImpl());
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        req.getRequestDispatcher(REGISTRATION_PAGE_JSP).forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        req.setCharacterEncoding("UTF-8");

        HashMap<String, String> registrationData = new HashMap<>();
        registrationData.put("name", req.getParameter("name"));
        registrationData.put("surname", req.getParameter("surname"));
        registrationData.put("email", req.getParameter("email"));
        registrationData.put("password", req.getParameter("password"));

        userService.saveNewUser(registrationData);

        req.getRequestDispatcher(LOGIN_PAGE_JSP).forward(req, resp);
    }
}
