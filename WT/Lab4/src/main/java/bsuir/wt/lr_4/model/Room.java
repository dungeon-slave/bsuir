package bsuir.wt.lr_4.model;

import lombok.*;

@Data
@Builder
@ToString
@NoArgsConstructor
@AllArgsConstructor
public class Room {

    private long room_id;
    RoomType roomType;
    private int floor;
    private float price;
}
