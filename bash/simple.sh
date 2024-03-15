clean_branch() {
  info "Pruning remote branches"
  git fetch --prune

  info "Fetching branch from origin: $1"
  git fetch origin $1
  
  info "Checkout branch: $1"
  git checkout $1

  info "Deleting branch except: $1"
  git branch | grep -v $1 | xargs -I_percent -- sh -c 'echo "Deleting branch _percent"; git branch -D _percent'

  info "Updating branch from origin"
  git pull origin $1
}

create_pull_request() {
   param=${1:-0}

  if [ $param = "ops" ]; then
    info "Creating PR with OPS REVIEWERS: $OPS_REVIEWERS"
    gh pr create -a @me -B dev -r "$OPS_REVIEWERS"
  elif [ $param = "inf" ]; then
    info "Creating PR with INF REVIEWERS: $INF_REVIEWERS"
    gh pr create -a @me -B dev -r "$INF_REVIEWERS"
  else
    info "Creating PR"
    gh pr create -a @me -B dev
  fi
}


