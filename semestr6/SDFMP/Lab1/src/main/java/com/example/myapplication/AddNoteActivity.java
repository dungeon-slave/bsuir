package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Calendar;

public class AddNoteActivity extends AppCompatActivity
{
    private EditText fileNameEdit;
    private EditText textEdit;
    private String oldFile;
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_note);
        fileNameEdit = findViewById(R.id.FileNameInput);
        textEdit = findViewById(R.id.TextInput);
    }
    @Override
    protected void onStart()
    {
        super.onStart();
        try
        {
            String filename = getIntent().getStringExtra("FILE_NAME");
            if (filename != null)
            {
                FileInputStream stream = openFileInput(filename);
                byte[] bytes = new byte[stream.available()];
                stream.read(bytes);
                fileNameEdit.setText(filename);
                textEdit.setText(new String(bytes));
                oldFile = fileNameEdit.getText().toString();
            }
        }
        catch (Exception e)
        {
            Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
        }
    }
    public void btnSaveClick(View view)
    {
        String fileName = fileNameEdit.getText().toString() + "$" + Calendar.getInstance().getTime();;
        String text = textEdit.getText().toString();

        if (!fileName.isEmpty())
        {
            try
            {
                if (oldFile != null)
                {
                    deleteFile(oldFile);
                }
                FileOutputStream stream = openFileOutput(fileName, MODE_APPEND);
                stream.write(text.getBytes());
                stream.close();
            }
            catch (Exception e)
            {
                Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
            }
            finally
            {
                Toast.makeText(this, "Note saved!", Toast.LENGTH_SHORT).show();
                startActivity(new Intent(this, MainActivity.class));
            }
        }
    }
    public void btnCancelClick(View view)
    {
        startActivity(new Intent(this, MainActivity.class));
    }

}