package com.example.myapplication;

import static android.view.View.*;
import androidx.appcompat.app.AppCompatActivity;
import androidx.cardview.widget.CardView;
import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.SearchView;
import android.widget.TextView;
import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MainActivity extends AppCompatActivity
{
    static Map<String, String> notesList = new HashMap<>();
    static LinearLayout listLayout;
    static float startX;
    static SearchView notesSearch;
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        listLayout = findViewById(R.id.NotesListLayout);
        notesSearch = (SearchView) findViewById(R.id.NotesSearchView);
        notesSearch.setOnQueryTextListener(new SearchView.OnQueryTextListener()
        {
            @Override
            public boolean onQueryTextSubmit(String query)
            {
                return false;
            }
            @Override
            public boolean onQueryTextChange(String query)
            {
                createCards(notesSearch.getQuery().toString());
                return false;
            }
        });
    }
    @Override
    protected void onStart()
    {
        super.onStart();
        updateNotesList();
        createCards("");
    }
    public void btnAddNodeClick(View view)
    {
        startActivity(new Intent(this, AddNoteActivity.class));
    }
    @SuppressLint("ClickableViewAccessibility")
    private void createCards(String filter)
    {
        listLayout.removeAllViewsInLayout();
        for (String currNote: notesList.keySet())
        {
            if (currNote.contains(filter) || filter == "")
            {
                OnClickListener click = view ->
                {
                    Intent intent = new Intent(MainActivity.this, AddNoteActivity.class);
                    intent.putExtra("FILE_NAME", currNote);
                    startActivity(intent);
                };
                @SuppressLint("ClickableViewAccessibility") OnTouchListener swipe = (view, event) ->
                {
                    switch (event.getAction())
                    {
                        case MotionEvent.ACTION_DOWN:
                        {
                            startX = event.getX();
                            break;
                        }
                        case MotionEvent.ACTION_MOVE:
                        {
                            float bias = event.getX() - startX;
                            var card = findViewById(view.getId());

                            view.setX(view.getX() + bias);
                            if (card instanceof CardView)
                            {
                                card.setBackgroundResource(Math.abs(view.getX()) > 400 ? R.color.cardDeleteColor : R.color.cardColor);
                            }

                            break;
                        }
                        case MotionEvent.ACTION_UP:
                        {
                            float card = view.getX();
                            if (Math.abs(card) > 400)
                            {
                                deleteFile(currNote);
                                updateNotesList();
                                createCards(filter);
                            }
                            else
                            {
                                view.setX(0);
                            }
                            break;
                        }
                    }
                    return false;
                };

                listLayout.addView(createCard(notesList.get(currNote), swipe, click));
            }
        }
    }
    @SuppressLint("ClickableViewAccessibility")
    private CardView createCard(String filename, OnTouchListener swipe, OnClickListener click)
    {
        CardView newCard = new CardView(this, null, R.attr.cardStyle);
        TextView textView = new TextView(this, null, 0, R.style.cardText);

        textView.setText(filename);
        newCard.addView(textView);
        newCard.setId(generateViewId());
        newCard.setOnTouchListener(swipe);
        newCard.setOnClickListener(click);

        return newCard;
    }
    private void updateNotesList()
    {
        File[] files = getFilesDir().listFiles();

        notesList.clear();
        for (File currFile: files)
        {
            notesList.put(currFile.getName(), currFile.getName().split("\\$")[0]);
        }
    }
}