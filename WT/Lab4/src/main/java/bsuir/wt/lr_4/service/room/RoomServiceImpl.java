package bsuir.wt.lr_4.service.room;

import bsuir.wt.lr_4.DAO.room.RoomDAO;
import bsuir.wt.lr_4.model.Room;

import java.util.List;

public class RoomServiceImpl implements RoomService {

    private final RoomDAO roomDAO;

    public RoomServiceImpl(RoomDAO roomDAO) {
        this.roomDAO = roomDAO;
    }

    @Override
    public List<Room> getAllRooms() {
        return roomDAO.getAll();
    }
}
