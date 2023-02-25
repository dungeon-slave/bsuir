"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Task = exports.tasks = void 0;
exports.tasks = [];
class Task {
    name;
    date;
    status;
    file;
    constructor(name, date, status, file) {
        this.name = name;
        this.date = date;
        this.status = status;
        this.file = file;
    }
}
exports.Task = Task;
