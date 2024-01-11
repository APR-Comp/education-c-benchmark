package com.example;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Random;
import java.util.Set;

import org.antlr.v4.runtime.CommonToken;
import org.antlr.v4.runtime.tree.TerminalNode;
import org.apache.commons.lang3.RandomStringUtils;

import com.example.c.CBaseListener;
import com.example.c.CLexer;
import com.example.c.CParser.DeclaratorContext;
import com.example.c.CParser.DirectDeclaratorContext;
import com.example.c.CParser.FunctionDefinitionContext;

public class Mangler extends CBaseListener {
    Random rng = new Random();
    Set<String> identifiers = new HashSet<String>();
    Set<String> forbiddenSet = new HashSet<String>();
    Map<String, String> obfuscation = new HashMap<String, String>();
    {
        forbiddenSet.add("printf");
        forbiddenSet.add("scanf");
        forbiddenSet.add("malloc");
        forbiddenSet.add("free");
        forbiddenSet.add("calloc");
        forbiddenSet.add("putc");
        forbiddenSet.add("strlen");
        forbiddenSet.add("strstr");
        forbiddenSet.add("getc");
        forbiddenSet.add("memset");
        forbiddenSet.add("memcpy");
        forbiddenSet.add("abs");
        forbiddenSet.add("min");
        forbiddenSet.add("max");
        forbiddenSet.add("pow");
        forbiddenSet.add("sqrtf");
        forbiddenSet.add("sqrt");
        forbiddenSet.add("getchar");
        forbiddenSet.add("fabs");
        forbiddenSet.add("main");
    }
    int obfuscationCount = 0;

    @Override
    public void visitTerminal(TerminalNode node) {

        // The amount of wrappings for most functions was this...
        if (node.getSymbol().getType() == CLexer.Identifier
                && node.getParent() instanceof DirectDeclaratorContext
                && node.getParent().getParent() instanceof DirectDeclaratorContext
                && node.getParent().getParent().getParent() instanceof DeclaratorContext
                && node.getParent().getParent().getParent().getParent() instanceof FunctionDefinitionContext) {
            forbiddenSet.add(node.getText()); // Ignore function definitions to ensure that they are called properly
        }

        if (node.getSymbol().getType() == CLexer.Identifier && !forbiddenSet.contains(node.getText())) {
            if (identifiers.add(node.getText())) {
                String x = String.format("var__%d", obfuscationCount++);

                obfuscation.put(node.getText(), x);
            }

            ((CommonToken) node.getSymbol()).setText(
                    obfuscation.get(node.getText()));

        }
    }
}