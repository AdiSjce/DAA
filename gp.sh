#!/bin/bash

# Set the repository name and URL
repo_name="DAA"
repo_url="https://github.com/AdiSjce/DAA.git"

# Set the commit message with date and time
commit_message="$(date)"

# Set your GitHub username
username="AdiSjce"

# Set your personal access token
token="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"

# Set the credential helper to use the token for authentication
git config --global credential.helper "store --file ~/.git-credentials"

# Store the credentials in a file
echo "$repo_url=https://$username:$token@github.com" > ~/.git-credentials

# Add all changes to the repository
git add .

# Commit the changes with the commit message
git commit -m "$commit_message"

# Push the changes to your repository
git push $repo_url master

# Remove the stored credentials
rm ~/.git-credentials
