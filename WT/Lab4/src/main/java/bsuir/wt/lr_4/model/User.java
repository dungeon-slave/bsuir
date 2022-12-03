package bsuir.wt.lr_4.model;

import lombok.*;

@Data
@Builder
@ToString
@NoArgsConstructor
@AllArgsConstructor
public class User {

    private long id;
    private String name;
    private String surname;
    private String email;
    private String password;
    private Role role;
}
