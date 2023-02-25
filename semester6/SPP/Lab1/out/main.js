"use strict";
// Разработать простое приложение с рендерингом на сервере. Например, список задач со статусом их выполнения, 
// фильтрацией по статусу и выставлением ожидаемой даты завершения, а так же возможностью прикреплять файлы к каждой задаче. 
// Сервер должен отдавать клиенту готовую разметку, отправка данных серверу должна осуществляться через отправку форм. 
// Обязательно использование NodeJS, конкретные библиотеки могут отличаться. Например, подойдут Express + EJS.
Object.defineProperty(exports, "__esModule", { value: true });
const Server_1 = require("./Server");
//------------------------MAIN--------------------------
let server = new Server_1.Server(7999);
server.app.listen(server.port, server.checkServer);
server.app.get('/', server.sendPage.bind(server));
server.app.get('/files', server.sendFile);
server.app.post('/tasks', server.getTask);
server.app.post('/filter', server.getFilter.bind(server));
