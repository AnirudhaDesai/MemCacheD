





<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">



  <link crossorigin="anonymous" href="https://assets-cdn.github.com/assets/frameworks-67bdbbece8dab4e0407b1dc8edc4fc44c6ddd91aaf7a7dd69cac694b4cb761c4.css" integrity="sha256-Z7277OjatOBAex3I7cT8RMbd2Rqven3WnKxpS0y3YcQ=" media="all" rel="stylesheet" />
  <link crossorigin="anonymous" href="https://assets-cdn.github.com/assets/github-82d26a01555805dfcbf0b92a2fed02dd7d26540fd1f58ec3c6f8a8e921600e1e.css" integrity="sha256-gtJqAVVYBd/L8LkqL+0C3X0mVA/R9Y7Dxvio6SFgDh4=" media="all" rel="stylesheet" />
  
  
  
  

  <meta name="viewport" content="width=device-width">
  
  <title>Spring2017/protocol.md at master · UMass-COMPSCI-630/Spring2017</title>
  <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub">
  <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub">
  <meta property="fb:app_id" content="1401488693436528">

    
    <meta content="https://avatars3.githubusercontent.com/u/25670106?v=3&amp;s=400" property="og:image" /><meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="UMass-COMPSCI-630/Spring2017" property="og:title" /><meta content="https://github.com/UMass-COMPSCI-630/Spring2017" property="og:url" /><meta content="Contribute to Spring2017 development by creating an account on GitHub." property="og:description" />

  <link rel="assets" href="https://assets-cdn.github.com/">
  <link rel="web-socket" href="wss://live.github.com/_sockets/VjI6MTU0NDY5ODUzOmQ1NjQyZTJlY2FkODFmYTAyMzNiMTAzZjE1NmIwODkwNDAxM2ZjZjI3MWZlNTM5NDM3MzNhZjQyN2JjZjQzZDU=--4a631b90f837c47a5a37d5d94688480a66cf976c">
  <meta name="pjax-timeout" content="1000">
  <link rel="sudo-modal" href="/sessions/sudo_modal">
  <meta name="request-id" content="F8C1:13609:2393066:38EBE40:58F0EEBB" data-pjax-transient>
  

  <meta name="selected-link" value="repo_source" data-pjax-transient>

  <meta name="google-site-verification" content="KT5gs8h0wvaagLKAVWq8bbeNwnZZK1r1XQysX3xurLU">
<meta name="google-site-verification" content="ZzhVyEFwb7w3e0-uOTltm8Jsck2F5StVihD0exw2fsA">
    <meta name="google-analytics" content="UA-3769691-2">

<meta content="collector.githubapp.com" name="octolytics-host" /><meta content="github" name="octolytics-app-id" /><meta content="https://collector.githubapp.com/github-external/browser_event" name="octolytics-event-url" /><meta content="F8C1:13609:2393066:38EBE40:58F0EEBB" name="octolytics-dimension-request_id" /><meta content="18730479" name="octolytics-actor-id" /><meta content="rvinitraumass" name="octolytics-actor-login" /><meta content="e986e3442d6384b8d4bbc63b9ec98a0ab81959af34898b336ea0103932a52c75" name="octolytics-actor-hash" />
<meta content="/&lt;user-name&gt;/&lt;repo-name&gt;/blob/show" data-pjax-transient="true" name="analytics-location" />




  <meta class="js-ga-set" name="dimension1" content="Logged In">


  

      <meta name="hostname" content="github.com">
  <meta name="user-login" content="rvinitraumass">

      <meta name="expected-hostname" content="github.com">
    <meta name="js-proxy-site-detection-payload" content="MDg1MWIyY2VlMzVmMDAwY2JiOTc4NDM2MDJiYTYzZWI2YmNhN2FkMGVlNDUxMmIzMjcwMjBhMTFkY2ZmMzU0Nnx7InJlbW90ZV9hZGRyZXNzIjoiNzMuNC4xMTUuMjUzIiwicmVxdWVzdF9pZCI6IkY4QzE6MTM2MDk6MjM5MzA2NjozOEVCRTQwOjU4RjBFRUJCIiwidGltZXN0YW1wIjoxNDkyMTg0NzY5LCJob3N0IjoiZ2l0aHViLmNvbSJ9">


  <meta name="html-safe-nonce" content="d45cc65712a2da44ac0062242b0f83ad21ec5304">

  <meta http-equiv="x-pjax-version" content="543291d3cbffec838ad53be985002a00">
  

    
  <meta name="description" content="Contribute to Spring2017 development by creating an account on GitHub.">
  <meta name="go-import" content="github.com/UMass-COMPSCI-630/Spring2017 git https://github.com/UMass-COMPSCI-630/Spring2017.git">

  <meta content="25670106" name="octolytics-dimension-user_id" /><meta content="UMass-COMPSCI-630" name="octolytics-dimension-user_login" /><meta content="81483657" name="octolytics-dimension-repository_id" /><meta content="UMass-COMPSCI-630/Spring2017" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="81483657" name="octolytics-dimension-repository_network_root_id" /><meta content="UMass-COMPSCI-630/Spring2017" name="octolytics-dimension-repository_network_root_nwo" />
        <link href="https://github.com/UMass-COMPSCI-630/Spring2017/commits/master.atom" rel="alternate" title="Recent Commits to Spring2017:master" type="application/atom+xml">


    <link rel="canonical" href="https://github.com/UMass-COMPSCI-630/Spring2017/blob/master/projects/project-3/protocol.md" data-pjax-transient>


  <meta name="browser-stats-url" content="https://api.github.com/_private/browser/stats">

  <meta name="browser-errors-url" content="https://api.github.com/_private/browser/errors">

  <link rel="mask-icon" href="https://assets-cdn.github.com/pinned-octocat.svg" color="#000000">
  <link rel="icon" type="image/x-icon" href="https://assets-cdn.github.com/favicon.ico">

<meta name="theme-color" content="#1e2327">


  <meta name="u2f-support" content="true">

  </head>

  <body class="logged-in env-production emoji-size-boost page-blob">
    


  <div class="position-relative js-header-wrapper ">
    <a href="#start-of-content" tabindex="1" class="accessibility-aid js-skip-to-content">Skip to content</a>
    <div id="js-pjax-loader-bar" class="pjax-loader-bar"><div class="progress"></div></div>

    
    
    



        
<div class="header" role="banner">
  <div class="container clearfix">
    <a class="header-logo-invertocat" href="https://github.com/" data-hotkey="g d" aria-label="Homepage" data-ga-click="Header, go to dashboard, icon:logo">
  <svg aria-hidden="true" class="octicon octicon-mark-github" height="32" version="1.1" viewBox="0 0 16 16" width="32"><path fill-rule="evenodd" d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0 0 16 8c0-4.42-3.58-8-8-8z"/></svg>
</a>


        <div class="header-search scoped-search site-scoped-search js-site-search" role="search">
  <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/UMass-COMPSCI-630/Spring2017/search" class="js-site-search-form" data-scoped-search-url="/UMass-COMPSCI-630/Spring2017/search" data-unscoped-search-url="/search" method="get"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /></div>
    <label class="form-control header-search-wrapper js-chromeless-input-container">
        <a href="/UMass-COMPSCI-630/Spring2017/blob/master/projects/project-3/protocol.md" class="header-search-scope no-underline">This repository</a>
      <input type="text"
        class="form-control header-search-input js-site-search-focus js-site-search-field is-clearable"
        data-hotkey="s"
        name="q"
        value=""
        placeholder="Search"
        aria-label="Search this repository"
        data-unscoped-placeholder="Search GitHub"
        data-scoped-placeholder="Search"
        autocapitalize="off">
        <input type="hidden" class="js-site-search-type-field" name="type" >
    </label>
</form></div>


      <ul class="header-nav float-left" role="navigation">
        <li class="header-nav-item">
          <a href="/pulls" aria-label="Pull requests you created" class="js-selected-navigation-item header-nav-link" data-ga-click="Header, click, Nav menu - item:pulls context:user" data-hotkey="g p" data-selected-links="/pulls /pulls/assigned /pulls/mentioned /pulls">
            Pull requests
</a>        </li>
        <li class="header-nav-item">
          <a href="/issues" aria-label="Issues you created" class="js-selected-navigation-item header-nav-link" data-ga-click="Header, click, Nav menu - item:issues context:user" data-hotkey="g i" data-selected-links="/issues /issues/assigned /issues/mentioned /issues">
            Issues
</a>        </li>
          <li class="header-nav-item">
            <a class="header-nav-link" href="https://gist.github.com/" data-ga-click="Header, go to gist, text:gist">Gist</a>
          </li>
      </ul>

    
<ul class="header-nav user-nav float-right" id="user-links">
  <li class="header-nav-item">
    

  </li>

  <li class="header-nav-item dropdown js-menu-container">
    <a class="header-nav-link tooltipped tooltipped-s js-menu-target" href="/new"
       aria-label="Create new…"
       data-ga-click="Header, create new, icon:add">
      <svg aria-hidden="true" class="octicon octicon-plus float-left" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 9H7v5H5V9H0V7h5V2h2v5h5z"/></svg>
      <span class="dropdown-caret"></span>
    </a>

    <div class="dropdown-menu-content js-menu-content">
      <ul class="dropdown-menu dropdown-menu-sw">
        
<a class="dropdown-item" href="/new" data-ga-click="Header, create new repository">
  New repository
</a>

  <a class="dropdown-item" href="/new/import" data-ga-click="Header, import a repository">
    Import repository
  </a>

<a class="dropdown-item" href="https://gist.github.com/" data-ga-click="Header, create new gist">
  New gist
</a>

  <a class="dropdown-item" href="/organizations/new" data-ga-click="Header, create new organization">
    New organization
  </a>



  <div class="dropdown-divider"></div>
  <div class="dropdown-header">
    <span title="UMass-COMPSCI-630/Spring2017">This repository</span>
  </div>
    <a class="dropdown-item" href="/UMass-COMPSCI-630/Spring2017/issues/new" data-ga-click="Header, create new issue">
      New issue
    </a>

      </ul>
    </div>
  </li>

  <li class="header-nav-item dropdown js-menu-container">
    <a class="header-nav-link name tooltipped tooltipped-sw js-menu-target" href="/rvinitraumass"
       aria-label="View profile and more"
       data-ga-click="Header, show menu, icon:avatar">
      <img alt="@rvinitraumass" class="avatar" src="https://avatars1.githubusercontent.com/u/18730479?v=3&amp;s=40" height="20" width="20">
      <span class="dropdown-caret"></span>
    </a>

    <div class="dropdown-menu-content js-menu-content">
      <div class="dropdown-menu dropdown-menu-sw">
        <div class="dropdown-header header-nav-current-user css-truncate">
          Signed in as <strong class="css-truncate-target">rvinitraumass</strong>
        </div>

        <div class="dropdown-divider"></div>

        <a class="dropdown-item" href="/rvinitraumass" data-ga-click="Header, go to profile, text:your profile">
          Your profile
        </a>
        <a class="dropdown-item" href="/rvinitraumass?tab=stars" data-ga-click="Header, go to starred repos, text:your stars">
          Your stars
        </a>
        <a class="dropdown-item" href="/explore" data-ga-click="Header, go to explore, text:explore">
          Explore
        </a>
          <a class="dropdown-item" href="/integrations" data-ga-click="Header, go to integrations, text:integrations">
            Integrations
          </a>
        <a class="dropdown-item" href="https://help.github.com" data-ga-click="Header, go to help, text:help">
          Help
        </a>

        <div class="dropdown-divider"></div>

        <a class="dropdown-item" href="/settings/profile" data-ga-click="Header, go to settings, icon:settings">
          Settings
        </a>

        <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/logout" class="logout-form" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="YHYEf/OINS6yv3t5a4g21/QcNEkiGM79fRBxjAJ9zctZTcffCKvm6GQTotpU/02J34fQiSkWqNVuC+HDpY+Zqg==" /></div>
          <button type="submit" class="dropdown-item dropdown-signout" data-ga-click="Header, sign out, icon:logout">
            Sign out
          </button>
</form>      </div>
    </div>
  </li>
</ul>


    <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/logout" class="sr-only right-0" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="/s0tVxH7DDdcCuQQozYiiRbvr0tj5MRWyuWjbFd4IWbH9u736tjf8YqmPbOcQVnXPXRLi2jqon7Z/jMj8Ip1Bw==" /></div>
      <button type="submit" class="dropdown-item dropdown-signout" data-ga-click="Header, sign out, icon:logout">
        Sign out
      </button>
</form>  </div>
</div>


      

  </div>

  <div id="start-of-content" class="accessibility-aid"></div>

    <div id="js-flash-container">
</div>



  <div role="main">
        <div itemscope itemtype="http://schema.org/SoftwareSourceCode">
    <div id="js-repo-pjax-container" data-pjax-container>
        



  <div class="pagehead repohead instapaper_ignore readability-menu experiment-repo-nav">
    <div class="container repohead-details-container">


      <ul class="pagehead-actions">
  <li>
        <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/notifications/subscribe" class="js-social-container" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="id2cThVGmfUdYOHvNdBLVqz7ipUbL0MhIcFlxXCOQrqfipfzEOhR2CPNdHlllvmgqPx6CvPoEKqwMUgLtBgehw==" /></div>      <input class="form-control" id="repository_id" name="repository_id" type="hidden" value="81483657" />

        <div class="select-menu js-menu-container js-select-menu">
          <a href="/UMass-COMPSCI-630/Spring2017/subscription"
            class="btn btn-sm btn-with-count select-menu-button js-menu-target" role="button" tabindex="0" aria-haspopup="true"
            data-ga-click="Repository, click Watch settings, action:blob#show">
            <span class="js-select-button">
              <svg aria-hidden="true" class="octicon octicon-eye" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"/></svg>
              Watch
            </span>
          </a>
          <a class="social-count js-social-count"
            href="/UMass-COMPSCI-630/Spring2017/watchers"
            aria-label="2 users are watching this repository">
            2
          </a>

        <div class="select-menu-modal-holder">
          <div class="select-menu-modal subscription-menu-modal js-menu-content">
            <div class="select-menu-header js-navigation-enable" tabindex="-1">
              <svg aria-label="Close" class="octicon octicon-x js-menu-close" height="16" role="img" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
              <span class="select-menu-title">Notifications</span>
            </div>

              <div class="select-menu-list js-navigation-container" role="menu">

                <div class="select-menu-item js-navigation-item selected" role="menuitem" tabindex="0">
                  <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
                  <div class="select-menu-item-text">
                    <input checked="checked" id="do_included" name="do" type="radio" value="included" />
                    <span class="select-menu-item-heading">Not watching</span>
                    <span class="description">Be notified when participating or @mentioned.</span>
                    <span class="js-select-button-text hidden-select-button-text">
                      <svg aria-hidden="true" class="octicon octicon-eye" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"/></svg>
                      Watch
                    </span>
                  </div>
                </div>

                <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
                  <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
                  <div class="select-menu-item-text">
                    <input id="do_subscribed" name="do" type="radio" value="subscribed" />
                    <span class="select-menu-item-heading">Watching</span>
                    <span class="description">Be notified of all conversations.</span>
                    <span class="js-select-button-text hidden-select-button-text">
                      <svg aria-hidden="true" class="octicon octicon-eye" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8.06 2C3 2 0 8 0 8s3 6 8.06 6C13 14 16 8 16 8s-3-6-7.94-6zM8 12c-2.2 0-4-1.78-4-4 0-2.2 1.8-4 4-4 2.22 0 4 1.8 4 4 0 2.22-1.78 4-4 4zm2-4c0 1.11-.89 2-2 2-1.11 0-2-.89-2-2 0-1.11.89-2 2-2 1.11 0 2 .89 2 2z"/></svg>
                      Unwatch
                    </span>
                  </div>
                </div>

                <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
                  <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
                  <div class="select-menu-item-text">
                    <input id="do_ignore" name="do" type="radio" value="ignore" />
                    <span class="select-menu-item-heading">Ignoring</span>
                    <span class="description">Never be notified.</span>
                    <span class="js-select-button-text hidden-select-button-text">
                      <svg aria-hidden="true" class="octicon octicon-mute" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8 2.81v10.38c0 .67-.81 1-1.28.53L3 10H1c-.55 0-1-.45-1-1V7c0-.55.45-1 1-1h2l3.72-3.72C7.19 1.81 8 2.14 8 2.81zm7.53 3.22l-1.06-1.06-1.97 1.97-1.97-1.97-1.06 1.06L11.44 8 9.47 9.97l1.06 1.06 1.97-1.97 1.97 1.97 1.06-1.06L13.56 8l1.97-1.97z"/></svg>
                      Stop ignoring
                    </span>
                  </div>
                </div>

              </div>

            </div>
          </div>
        </div>
</form>
  </li>

  <li>
      <div class="js-toggler-container js-social-container starring-container ">
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/UMass-COMPSCI-630/Spring2017/unstar" class="starred" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="NGKYNMo17pcBEoR4Q5uVUV2VswcPO6sMs3EUssv+VGzyzsupbRFNjF9oKdyCaBAUfUHIaYIRMb4IfEXxL68pcQ==" /></div>
      <button
        type="submit"
        class="btn btn-sm btn-with-count js-toggler-target"
        aria-label="Unstar this repository" title="Unstar UMass-COMPSCI-630/Spring2017"
        data-ga-click="Repository, click unstar button, action:blob#show; text:Unstar">
        <svg aria-hidden="true" class="octicon octicon-star" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M14 6l-4.9-.64L7 1 4.9 5.36 0 6l3.6 3.26L2.67 14 7 11.67 11.33 14l-.93-4.74z"/></svg>
        Unstar
      </button>
        <a class="social-count js-social-count" href="/UMass-COMPSCI-630/Spring2017/stargazers"
           aria-label="1 user starred this repository">
          1
        </a>
</form>
    <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/UMass-COMPSCI-630/Spring2017/star" class="unstarred" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="sFRsIla3tZTzu5HnhffIlkkRgaxcynmQ/EmPPvTpT0x9ff0Sn/xuUwpTxNCVo8KhbG46qbMp3OsOEYB5ZPkDKw==" /></div>
      <button
        type="submit"
        class="btn btn-sm btn-with-count js-toggler-target"
        aria-label="Star this repository" title="Star UMass-COMPSCI-630/Spring2017"
        data-ga-click="Repository, click star button, action:blob#show; text:Star">
        <svg aria-hidden="true" class="octicon octicon-star" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M14 6l-4.9-.64L7 1 4.9 5.36 0 6l3.6 3.26L2.67 14 7 11.67 11.33 14l-.93-4.74z"/></svg>
        Star
      </button>
        <a class="social-count js-social-count" href="/UMass-COMPSCI-630/Spring2017/stargazers"
           aria-label="1 user starred this repository">
          1
        </a>
</form>  </div>

  </li>

  <li>
          <a href="#fork-destination-box" class="btn btn-sm btn-with-count"
              title="Fork your own copy of UMass-COMPSCI-630/Spring2017 to your account"
              aria-label="Fork your own copy of UMass-COMPSCI-630/Spring2017 to your account"
              rel="facebox"
              data-ga-click="Repository, show fork modal, action:blob#show; text:Fork">
              <svg aria-hidden="true" class="octicon octicon-repo-forked" height="16" version="1.1" viewBox="0 0 10 16" width="10"><path fill-rule="evenodd" d="M8 1a1.993 1.993 0 0 0-1 3.72V6L5 8 3 6V4.72A1.993 1.993 0 0 0 2 1a1.993 1.993 0 0 0-1 3.72V6.5l3 3v1.78A1.993 1.993 0 0 0 5 15a1.993 1.993 0 0 0 1-3.72V9.5l3-3V4.72A1.993 1.993 0 0 0 8 1zM2 4.2C1.34 4.2.8 3.65.8 3c0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3 10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3-10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"/></svg>
            Fork
          </a>

          <div id="fork-destination-box" style="display: none;">
            <h2 class="facebox-header" data-facebox-id="facebox-header">Where should we fork this repository?</h2>
            <include-fragment src=""
                class="js-fork-select-fragment fork-select-fragment"
                data-url="/UMass-COMPSCI-630/Spring2017/fork?fragment=1">
              <img alt="Loading" height="64" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-128.gif" width="64" />
            </include-fragment>
          </div>

    <a href="/UMass-COMPSCI-630/Spring2017/network" class="social-count"
       aria-label="17 users forked this repository">
      17
    </a>
  </li>
</ul>

      <h1 class="public ">
  <svg aria-hidden="true" class="octicon octicon-repo" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M4 9H3V8h1v1zm0-3H3v1h1V6zm0-2H3v1h1V4zm0-2H3v1h1V2zm8-1v12c0 .55-.45 1-1 1H6v2l-1.5-1.5L3 16v-2H1c-.55 0-1-.45-1-1V1c0-.55.45-1 1-1h10c.55 0 1 .45 1 1zm-1 10H1v2h2v-1h3v1h5v-2zm0-10H2v9h9V1z"/></svg>
  <span class="author" itemprop="author"><a href="/UMass-COMPSCI-630" class="url fn" rel="author">UMass-COMPSCI-630</a></span><!--
--><span class="path-divider">/</span><!--
--><strong itemprop="name"><a href="/UMass-COMPSCI-630/Spring2017" data-pjax="#js-repo-pjax-container">Spring2017</a></strong>

</h1>

    </div>
    <div class="container">
      
<nav class="reponav js-repo-nav js-sidenav-container-pjax"
     itemscope
     itemtype="http://schema.org/BreadcrumbList"
     role="navigation"
     data-pjax="#js-repo-pjax-container">

  <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
    <a href="/UMass-COMPSCI-630/Spring2017" class="js-selected-navigation-item selected reponav-item" data-hotkey="g c" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches /UMass-COMPSCI-630/Spring2017" itemprop="url">
      <svg aria-hidden="true" class="octicon octicon-code" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M9.5 3L8 4.5 11.5 8 8 11.5 9.5 13 14 8 9.5 3zm-5 0L0 8l4.5 5L6 11.5 2.5 8 6 4.5 4.5 3z"/></svg>
      <span itemprop="name">Code</span>
      <meta itemprop="position" content="1">
</a>  </span>

    <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
      <a href="/UMass-COMPSCI-630/Spring2017/issues" class="js-selected-navigation-item reponav-item" data-hotkey="g i" data-selected-links="repo_issues repo_labels repo_milestones /UMass-COMPSCI-630/Spring2017/issues" itemprop="url">
        <svg aria-hidden="true" class="octicon octicon-issue-opened" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M7 2.3c3.14 0 5.7 2.56 5.7 5.7s-2.56 5.7-5.7 5.7A5.71 5.71 0 0 1 1.3 8c0-3.14 2.56-5.7 5.7-5.7zM7 1C3.14 1 0 4.14 0 8s3.14 7 7 7 7-3.14 7-7-3.14-7-7-7zm1 3H6v5h2V4zm0 6H6v2h2v-2z"/></svg>
        <span itemprop="name">Issues</span>
        <span class="counter">0</span>
        <meta itemprop="position" content="2">
</a>    </span>

  <span itemscope itemtype="http://schema.org/ListItem" itemprop="itemListElement">
    <a href="/UMass-COMPSCI-630/Spring2017/pulls" class="js-selected-navigation-item reponav-item" data-hotkey="g p" data-selected-links="repo_pulls /UMass-COMPSCI-630/Spring2017/pulls" itemprop="url">
      <svg aria-hidden="true" class="octicon octicon-git-pull-request" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M11 11.28V5c-.03-.78-.34-1.47-.94-2.06C9.46 2.35 8.78 2.03 8 2H7V0L4 3l3 3V4h1c.27.02.48.11.69.31.21.2.3.42.31.69v6.28A1.993 1.993 0 0 0 10 15a1.993 1.993 0 0 0 1-3.72zm-1 2.92c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zM4 3c0-1.11-.89-2-2-2a1.993 1.993 0 0 0-1 3.72v6.56A1.993 1.993 0 0 0 2 15a1.993 1.993 0 0 0 1-3.72V4.72c.59-.34 1-.98 1-1.72zm-.8 10c0 .66-.55 1.2-1.2 1.2-.65 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2zM2 4.2C1.34 4.2.8 3.65.8 3c0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"/></svg>
      <span itemprop="name">Pull requests</span>
      <span class="counter">0</span>
      <meta itemprop="position" content="3">
</a>  </span>

    <a href="/UMass-COMPSCI-630/Spring2017/projects" class="js-selected-navigation-item reponav-item" data-selected-links="repo_projects new_repo_project repo_project /UMass-COMPSCI-630/Spring2017/projects">
      <svg aria-hidden="true" class="octicon octicon-project" height="16" version="1.1" viewBox="0 0 15 16" width="15"><path fill-rule="evenodd" d="M10 12h3V2h-3v10zm-4-2h3V2H6v8zm-4 4h3V2H2v12zm-1 1h13V1H1v14zM14 0H1a1 1 0 0 0-1 1v14a1 1 0 0 0 1 1h13a1 1 0 0 0 1-1V1a1 1 0 0 0-1-1z"/></svg>
      Projects
      <span class="counter">0</span>
</a>
    <a href="/UMass-COMPSCI-630/Spring2017/wiki" class="js-selected-navigation-item reponav-item" data-hotkey="g w" data-selected-links="repo_wiki /UMass-COMPSCI-630/Spring2017/wiki">
      <svg aria-hidden="true" class="octicon octicon-book" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M3 5h4v1H3V5zm0 3h4V7H3v1zm0 2h4V9H3v1zm11-5h-4v1h4V5zm0 2h-4v1h4V7zm0 2h-4v1h4V9zm2-6v9c0 .55-.45 1-1 1H9.5l-1 1-1-1H2c-.55 0-1-.45-1-1V3c0-.55.45-1 1-1h5.5l1 1 1-1H15c.55 0 1 .45 1 1zm-8 .5L7.5 3H2v9h6V3.5zm7-.5H9.5l-.5.5V12h6V3z"/></svg>
      Wiki
</a>

  <a href="/UMass-COMPSCI-630/Spring2017/pulse" class="js-selected-navigation-item reponav-item" data-selected-links="pulse /UMass-COMPSCI-630/Spring2017/pulse">
    <svg aria-hidden="true" class="octicon octicon-pulse" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M11.5 8L8.8 5.4 6.6 8.5 5.5 1.6 2.38 8H0v2h3.6l.9-1.8.9 5.4L9 8.5l1.6 1.5H14V8z"/></svg>
    Pulse
</a>
  <a href="/UMass-COMPSCI-630/Spring2017/graphs" class="js-selected-navigation-item reponav-item" data-selected-links="repo_graphs repo_contributors /UMass-COMPSCI-630/Spring2017/graphs">
    <svg aria-hidden="true" class="octicon octicon-graph" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M16 14v1H0V0h1v14h15zM5 13H3V8h2v5zm4 0H7V3h2v10zm4 0h-2V6h2v7z"/></svg>
    Graphs
</a>

</nav>

    </div>
  </div>

<div class="container new-discussion-timeline experiment-repo-nav">
  <div class="repository-content">

    
          

<a href="/UMass-COMPSCI-630/Spring2017/blob/252129c4afd04679c363b8675cba127b6d939751/projects/project-3/protocol.md" class="d-none js-permalink-shortcut" data-hotkey="y">Permalink</a>

<!-- blob contrib key: blob_contributors:v21:940a963517857e1b8f6126ef5b6882d7 -->

<div class="file-navigation js-zeroclipboard-container">
  
<div class="select-menu branch-select-menu js-menu-container js-select-menu float-left">
  <button class=" btn btn-sm select-menu-button js-menu-target css-truncate" data-hotkey="w"
    
    type="button" aria-label="Switch branches or tags" tabindex="0" aria-haspopup="true">
      <i>Branch:</i>
      <span class="js-select-button css-truncate-target">master</span>
  </button>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax>

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <svg aria-label="Close" class="octicon octicon-x js-menu-close" height="16" role="img" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
        <span class="select-menu-title">Switch branches/tags</span>
      </div>

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Filter branches/tags" id="context-commitish-filter-field" class="form-control js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" data-filter-placeholder="Filter branches/tags" class="js-select-menu-tab" role="tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" data-filter-placeholder="Find a tag…" class="js-select-menu-tab" role="tab">Tags</a>
            </li>
          </ul>
        </div>
      </div>

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches" role="menu">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <a class="select-menu-item js-navigation-item js-navigation-open selected"
               href="/UMass-COMPSCI-630/Spring2017/blob/master/projects/project-3/protocol.md"
               data-name="master"
               data-skip-pjax="true"
               rel="nofollow">
              <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"/></svg>
              <span class="select-menu-item-text css-truncate-target js-select-menu-filter-text">
                master
              </span>
            </a>
        </div>

          <div class="select-menu-no-results">Nothing to show</div>
      </div>

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div>

    </div>
  </div>
</div>

  <div class="BtnGroup float-right">
    <a href="/UMass-COMPSCI-630/Spring2017/find/master"
          class="js-pjax-capture-input btn btn-sm BtnGroup-item"
          data-pjax
          data-hotkey="t">
      Find file
    </a>
    <button aria-label="Copy file path to clipboard" class="js-zeroclipboard btn btn-sm BtnGroup-item tooltipped tooltipped-s" data-copied-hint="Copied!" type="button">Copy path</button>
  </div>
  <div class="breadcrumb js-zeroclipboard-target">
    <span class="repo-root js-repo-root"><span class="js-path-segment"><a href="/UMass-COMPSCI-630/Spring2017"><span>Spring2017</span></a></span></span><span class="separator">/</span><span class="js-path-segment"><a href="/UMass-COMPSCI-630/Spring2017/tree/master/projects"><span>projects</span></a></span><span class="separator">/</span><span class="js-path-segment"><a href="/UMass-COMPSCI-630/Spring2017/tree/master/projects/project-3"><span>project-3</span></a></span><span class="separator">/</span><strong class="final-path">protocol.md</strong>
  </div>
</div>



  <div class="commit-tease">
      <span class="float-right">
        <a class="commit-tease-sha" href="/UMass-COMPSCI-630/Spring2017/commit/2853bcedc18693341a717eb642ccd690143ed39c" data-pjax>
          2853bce
        </a>
        <relative-time datetime="2017-04-14T00:51:45Z">Apr 13, 2017</relative-time>
      </span>
      <div>
        <img alt="@emeryberger" class="avatar" height="20" src="https://avatars0.githubusercontent.com/u/1612723?v=3&amp;s=40" width="20" />
        <a href="/emeryberger" class="user-mention" rel="contributor">emeryberger</a>
          <a href="/UMass-COMPSCI-630/Spring2017/commit/2853bcedc18693341a717eb642ccd690143ed39c" class="message" data-pjax="true" title="Initial.">Initial.</a>
      </div>

    <div class="commit-tease-contributors">
      <button type="button" class="btn-link muted-link contributors-toggle" data-facebox="#blob_contributors_box">
        <strong>1</strong>
         contributor
      </button>
      
    </div>

    <div id="blob_contributors_box" style="display:none">
      <h2 class="facebox-header" data-facebox-id="facebox-header">Users who have contributed to this file</h2>
      <ul class="facebox-user-list" data-facebox-id="facebox-description">
          <li class="facebox-user-list-item">
            <img alt="@emeryberger" height="24" src="https://avatars2.githubusercontent.com/u/1612723?v=3&amp;s=48" width="24" />
            <a href="/emeryberger">emeryberger</a>
          </li>
      </ul>
    </div>
  </div>

<div class="file">
  <div class="file-header">
  <div class="file-actions">

    <div class="BtnGroup">
      <a href="/UMass-COMPSCI-630/Spring2017/raw/master/projects/project-3/protocol.md" class="btn btn-sm BtnGroup-item" id="raw-url">Raw</a>
        <a href="/UMass-COMPSCI-630/Spring2017/blame/master/projects/project-3/protocol.md" class="btn btn-sm js-update-url-with-hash BtnGroup-item" data-hotkey="b">Blame</a>
      <a href="/UMass-COMPSCI-630/Spring2017/commits/master/projects/project-3/protocol.md" class="btn btn-sm BtnGroup-item" rel="nofollow">History</a>
    </div>

        <a class="btn-octicon tooltipped tooltipped-nw"
           href="github-mac://openRepo/https://github.com/UMass-COMPSCI-630/Spring2017?branch=master&amp;filepath=projects%2Fproject-3%2Fprotocol.md"
           aria-label="Open this file in GitHub Desktop"
           data-ga-click="Repository, open with desktop, type:mac">
            <svg aria-hidden="true" class="octicon octicon-device-desktop" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M15 2H1c-.55 0-1 .45-1 1v9c0 .55.45 1 1 1h5.34c-.25.61-.86 1.39-2.34 2h8c-1.48-.61-2.09-1.39-2.34-2H15c.55 0 1-.45 1-1V3c0-.55-.45-1-1-1zm0 9H1V3h14v8z"/></svg>
        </a>

        <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/UMass-COMPSCI-630/Spring2017/edit/master/projects/project-3/protocol.md" class="inline-form js-update-url-with-hash" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="BSTPWGaNt2qmgH5yt2IEfmUyPlVveEXdNrJG33Uq08nZb7HzmQHBpUcYjUBz5hPfvU+DfFaLQPSv9NdkctlD+A==" /></div>
          <button class="btn-octicon tooltipped tooltipped-nw" type="submit"
            aria-label="Fork this project and edit the file" data-hotkey="e" data-disable-with>
            <svg aria-hidden="true" class="octicon octicon-pencil" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path fill-rule="evenodd" d="M0 12v3h3l8-8-3-3-8 8zm3 2H1v-2h1v1h1v1zm10.3-9.3L12 6 9 3l1.3-1.3a.996.996 0 0 1 1.41 0l1.59 1.59c.39.39.39 1.02 0 1.41z"/></svg>
          </button>
</form>        <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="/UMass-COMPSCI-630/Spring2017/delete/master/projects/project-3/protocol.md" class="inline-form" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="VAn9KyevqwIjEeQx0QcjP+UpEt5r6omeJ7sYMzEtGq18Pd0+FDbG5P/lVJazllHXn7AP4jjEorPZQO5HimrlpQ==" /></div>
          <button class="btn-octicon btn-octicon-danger tooltipped tooltipped-nw" type="submit"
            aria-label="Fork this project and delete the file" data-disable-with>
            <svg aria-hidden="true" class="octicon octicon-trashcan" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M11 2H9c0-.55-.45-1-1-1H5c-.55 0-1 .45-1 1H2c-.55 0-1 .45-1 1v1c0 .55.45 1 1 1v9c0 .55.45 1 1 1h7c.55 0 1-.45 1-1V5c.55 0 1-.45 1-1V3c0-.55-.45-1-1-1zm-1 12H3V5h1v8h1V5h1v8h1V5h1v8h1V5h1v9zm1-10H2V3h9v1z"/></svg>
          </button>
</form>  </div>

  <div class="file-info">
      1133 lines (860 sloc)
      <span class="file-info-divider"></span>
    51.3 KB
  </div>
</div>

  
  <div id="readme" class="readme blob instapaper_body">
    <article class="markdown-body entry-content" itemprop="text"><h2><a id="user-content-protocol" class="anchor" href="#protocol" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Protocol</h2>
<p>Clients of memcached communicate with server through TCP connections.
(A UDP interface is also available; details are below under "UDP
protocol.") A given running memcached server listens on some
(configurable) port; clients connect to that port, send commands to
the server, read responses, and eventually close the connection.</p>
<p>There is no need to send any command to end the session. A client may
just close the connection at any moment it no longer needs it. Note,
however, that clients are encouraged to cache their connections rather
than reopen them every time they need to store or retrieve data.  This
is because memcached is especially designed to work very efficiently
with a very large number (many hundreds, more than a thousand if
necessary) of open connections. Caching connections will eliminate the
overhead associated with establishing a TCP connection (the overhead
of preparing for a new connection on the server side is insignificant
compared to this).</p>
<p>There are two kinds of data sent in the memcache protocol: text lines
and unstructured data.  Text lines are used for commands from clients
and responses from servers. Unstructured data is sent when a client
wants to store or retrieve data. The server will transmit back
unstructured data in exactly the same way it received it, as a byte
stream. The server doesn't care about byte order issues in
unstructured data and isn't aware of them. There are no limitations on
characters that may appear in unstructured data; however, the reader
of such data (either a client or a server) will always know, from a
preceding text line, the exact length of the data block being
transmitted.</p>
<p>Text lines are always terminated by \r\n. Unstructured data is <em>also</em>
terminated by \r\n, even though \r, \n or any other 8-bit characters
may also appear inside the data. Therefore, when a client retrieves
data from a server, it must use the length of the data block (which it
will be provided with) to determine where the data block ends, and not
the fact that \r\n follows the end of the data block, even though it
does.</p>
<h2><a id="user-content-keys" class="anchor" href="#keys" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Keys</h2>
<p>Data stored by memcached is identified with the help of a key. A key
is a text string which should uniquely identify the data for clients
that are interested in storing and retrieving it.  Currently the
length limit of a key is set at 250 characters (of course, normally
clients wouldn't need to use such long keys); the key must not include
control characters or whitespace.</p>
<h2><a id="user-content-commands" class="anchor" href="#commands" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Commands</h2>
<p>There are three types of commands.</p>
<p>Storage commands (there are six: "set", "add", "replace", "append"
"prepend" and "cas") ask the server to store some data identified by a
key. The client sends a command line, and then a data block; after
that the client expects one line of response, which will indicate
success or failure.</p>
<p>Retrieval commands (there are two: "get" and "gets") ask the server to
retrieve data corresponding to a set of keys (one or more keys in one
request). The client sends a command line, which includes all the
requested keys; after that for each item the server finds it sends to
the client one response line with information about the item, and one
data block with the item's data; this continues until the server
finished with the "END" response line.</p>
<p>All other commands don't involve unstructured data. In all of them,
the client sends one command line, and expects (depending on the
command) either one line of response, or several lines of response
ending with "END" on the last line.</p>
<p>A command line always starts with the name of the command, followed by
parameters (if any) delimited by whitespace. Command names are
lower-case and are case-sensitive.</p>
<h2><a id="user-content-expiration-times" class="anchor" href="#expiration-times" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Expiration times</h2>
<p>Some commands involve a client sending some kind of expiration time
(relative to an item or to an operation requested by the client) to
the server. In all such cases, the actual value sent may either be
Unix time (number of seconds since January 1, 1970, as a 32-bit
value), or a number of seconds starting from current time. In the
latter case, this number of seconds may not exceed 60<em>60</em>24*30 (number
of seconds in 30 days); if the number sent by a client is larger than
that, the server will consider it to be real Unix time value rather
than an offset from current time.</p>
<h2><a id="user-content-error-strings" class="anchor" href="#error-strings" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Error strings</h2>
<p>Each command sent by a client may be answered with an error string
from the server. These error strings come in three types:</p>
<ul>
<li>
<p>"ERROR\r\n"</p>
<p>means the client sent a nonexistent command name.</p>
</li>
<li>
<p>"CLIENT_ERROR \r\n"</p>
<p>means some sort of client error in the input line, i.e. the input
doesn't conform to the protocol in some way.  is a
human-readable error string.</p>
</li>
<li>
<p>"SERVER_ERROR \r\n"</p>
<p>means some sort of server error prevents the server from carrying
out the command.  is a human-readable error string. In cases
of severe server errors, which make it impossible to continue
serving the client (this shouldn't normally happen), the server will
close the connection after sending the error line. This is the only
case in which the server closes a connection to a client.</p>
</li>
</ul>
<p>In the descriptions of individual commands below, these error lines
are not again specifically mentioned, but clients must allow for their
possibility.</p>
<h2><a id="user-content-storage-commands" class="anchor" href="#storage-commands" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Storage commands</h2>
<p>First, the client sends a command line which looks like this:</p>
<p>     [noreply]\r\n
cas      [noreply]\r\n</p>
<ul>
<li>
<p> is "set", "add", "replace", "append" or "prepend"</p>
<p>"set" means "store this data".</p>
<p>"add" means "store this data, but only if the server <em>doesn't</em> already
hold data for this key".</p>
<p>"replace" means "store this data, but only if the server <em>does</em>
already hold data for this key".</p>
<p>"append" means "add this data to an existing key after existing data".</p>
<p>"prepend" means "add this data to an existing key before existing data".</p>
<p>The append and prepend commands do not accept flags or exptime.
They update existing data portions, and ignore new flag and exptime
settings.</p>
<p>"cas" is a check and set operation which means "store this data but
only if no one else has updated since I last fetched it."</p>
</li>
<li>
<p> is the key under which the client asks to store the data</p>
</li>
<li>
<p> is an arbitrary 16-bit unsigned integer (written out in
decimal) that the server stores along with the data and sends back
when the item is retrieved. Clients may use this as a bit field to
store data-specific information; this field is opaque to the server.
Note that in memcached 1.2.1 and higher, flags may be 32-bits, instead
of 16, but you might want to restrict yourself to 16 bits for
compatibility with older versions.</p>
</li>
<li>
<p> is expiration time. If it's 0, the item never expires
(although it may be deleted from the cache to make place for other
items). If it's non-zero (either Unix time or offset in seconds from
current time), it is guaranteed that clients will not be able to
retrieve this item after the expiration time arrives (measured by
server time). If a negative value is given the item is immediately
expired.</p>
</li>
<li>
<p> is the number of bytes in the data block to follow, <em>not</em>
including the delimiting \r\n.  may be zero (in which case
it's followed by an empty data block).</p>
</li>
<li>
<p> is a unique 64-bit value of an existing entry.
Clients should use the value returned from the "gets" command
when issuing "cas" updates.</p>
</li>
<li>
<p>"noreply" optional parameter instructs the server to not send the
reply.  NOTE: if the request line is malformed, the server can't
parse "noreply" option reliably.  In this case it may send the error
to the client, and not reading it on the client side will break
things.  Client should construct only valid requests.</p>
</li>
</ul>
<p>After this line, the client sends the data block:</p>
<p>\r\n</p>
<ul>
<li> is a chunk of arbitrary 8-bit data of length 
from the previous line.</li>
</ul>
<p>After sending the command line and the data block the client awaits
the reply, which may be:</p>
<ul>
<li>
<p>"STORED\r\n", to indicate success.</p>
</li>
<li>
<p>"NOT_STORED\r\n" to indicate the data was not stored, but not
because of an error. This normally means that the
condition for an "add" or a "replace" command wasn't met.</p>
</li>
<li>
<p>"EXISTS\r\n" to indicate that the item you are trying to store with
a "cas" command has been modified since you last fetched it.</p>
</li>
<li>
<p>"NOT_FOUND\r\n" to indicate that the item you are trying to store
with a "cas" command did not exist.</p>
</li>
</ul>
<h2><a id="user-content-retrieval-command" class="anchor" href="#retrieval-command" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Retrieval command:</h2>
<p>The retrieval commands "get" and "gets" operate like this:</p>
<p>get <em>\r\n
gets </em>\r\n</p>
<ul>
<li>* means one or more key strings separated by whitespace.</li>
</ul>
<p>After this command, the client expects zero or more items, each of
which is received as a text line followed by a data block. After all
the items have been transmitted, the server sends the string</p>
<p>"END\r\n"</p>
<p>to indicate the end of response.</p>
<p>Each item sent by the server looks like this:</p>
<p>VALUE    []\r\n
\r\n</p>
<ul>
<li>
<p> is the key for the item being sent</p>
</li>
<li>
<p> is the flags value set by the storage command</p>
</li>
<li>
<p> is the length of the data block to follow, <em>not</em> including
its delimiting \r\n</p>
</li>
<li>
<p> is a unique 64-bit integer that uniquely identifies
this specific item.</p>
</li>
<li>
<p> is the data for this item.</p>
</li>
</ul>
<p>If some of the keys appearing in a retrieval request are not sent back
by the server in the item list this means that the server does not
hold items with such keys (because they were never stored, or stored
but deleted to make space for more items, or expired, or explicitly
deleted by a client).</p>
<h2><a id="user-content-deletion" class="anchor" href="#deletion" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Deletion</h2>
<p>The command "delete" allows for explicit deletion of items:</p>
<p>delete  [noreply]\r\n</p>
<ul>
<li>
<p> is the key of the item the client wishes the server to delete</p>
</li>
<li>
<p>"noreply" optional parameter instructs the server to not send the
reply.  See the note in Storage commands regarding malformed
requests.</p>
</li>
</ul>
<p>The response line to this command can be one of:</p>
<ul>
<li>
<p>"DELETED\r\n" to indicate success</p>
</li>
<li>
<p>"NOT_FOUND\r\n" to indicate that the item with this key was not
found.</p>
</li>
</ul>
<p>See the "flush_all" command below for immediate invalidation
of all existing items.</p>
<h2><a id="user-content-incrementdecrement" class="anchor" href="#incrementdecrement" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Increment/Decrement</h2>
<p>Commands "incr" and "decr" are used to change data for some item
in-place, incrementing or decrementing it. The data for the item is
treated as decimal representation of a 64-bit unsigned integer.  If
the current data value does not conform to such a representation, the
incr/decr commands return an error (memcached &lt;= 1.2.6 treated the
bogus value as if it were 0, leading to confusion). Also, the item
must already exist for incr/decr to work; these commands won't pretend
that a non-existent key exists with value 0; instead, they will fail.</p>
<p>The client sends the command line:</p>
<p>incr   [noreply]\r\n</p>
<p>or</p>
<p>decr   [noreply]\r\n</p>
<ul>
<li>
<p> is the key of the item the client wishes to change</p>
</li>
<li>
<p> is the amount by which the client wants to increase/decrease
the item. It is a decimal representation of a 64-bit unsigned integer.</p>
</li>
<li>
<p>"noreply" optional parameter instructs the server to not send the
reply.  See the note in Storage commands regarding malformed
requests.</p>
</li>
</ul>
<p>The response will be one of:</p>
<ul>
<li>
<p>"NOT_FOUND\r\n" to indicate the item with this value was not found</p>
</li>
<li>
<p>\r\n , where  is the new value of the item's data,
after the increment/decrement operation was carried out.</p>
</li>
</ul>
<p>Note that underflow in the "decr" command is caught: if a client tries
to decrease the value below 0, the new value will be 0.  Overflow in
the "incr" command will wrap around the 64 bit mark.</p>
<p>Note also that decrementing a number such that it loses length isn't
guaranteed to decrement its returned length.  The number MAY be
space-padded at the end, but this is purely an implementation
optimization, so you also shouldn't rely on that.</p>
<h2><a id="user-content-touch" class="anchor" href="#touch" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Touch</h2>
<p>The "touch" command is used to update the expiration time of an existing item
without fetching it.</p>
<p>touch   [noreply]\r\n</p>
<ul>
<li>
<p> is the key of the item the client wishes the server to touch</p>
</li>
<li>
<p> is expiration time. Works the same as with the update commands
(set/add/etc). This replaces the existing expiration time. If an existing
item were to expire in 10 seconds, but then was touched with an
expiration time of "20", the item would then expire in 20 seconds.</p>
</li>
<li>
<p>"noreply" optional parameter instructs the server to not send the
reply.  See the note in Storage commands regarding malformed
requests.</p>
</li>
</ul>
<p>The response line to this command can be one of:</p>
<ul>
<li>
<p>"TOUCHED\r\n" to indicate success</p>
</li>
<li>
<p>"NOT_FOUND\r\n" to indicate that the item with this key was not
found.</p>
</li>
</ul>
<h2><a id="user-content-slabs-reassign" class="anchor" href="#slabs-reassign" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Slabs Reassign</h2>
<p>NOTE: This command is subject to change as of this writing.</p>
<p>The slabs reassign command is used to redistribute memory once a running
instance has hit its limit. It might be desirable to have memory laid out
differently than was automatically assigned after the server started.</p>
<p>slabs reassign  \r\n</p>
<ul>
<li>
 is an id number for the slab class to steal a page from
</li>
</ul>
<p>A source class id of -1 means "pick from any valid class"</p>
<ul>
<li> is an id number for the slab class to move a page to</li>
</ul>
<p>The response line could be one of:</p>
<ul>
<li>
<p>"OK" to indicate the page has been scheduled to move</p>
</li>
<li>
<p>"BUSY [message]" to indicate a page is already being processed, try again
later.</p>
</li>
<li>
<p>"BADCLASS [message]" a bad class id was specified</p>
</li>
<li>
<p>"NOSPARE [message]" source class has no spare pages</p>
</li>
<li>
<p>"NOTFULL [message]" dest class must be full to move new pages to it</p>
</li>
<li>
<p>"UNSAFE [message]" source class cannot move a page right now</p>
</li>
<li>
<p>"SAME [message]" must specify different source/dest ids.</p>
</li>
</ul>
<h2><a id="user-content-slabs-automove" class="anchor" href="#slabs-automove" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Slabs Automove</h2>
<p>NOTE: This command is subject to change as of this writing.</p>
<p>The slabs automove command enables a background thread which decides on its
own when to move memory between slab classes. Its implementation and options
will likely be in flux for several versions. See the wiki/mailing list for
more details.</p>
<p>The automover can be enabled or disabled at runtime with this command.</p>
<p>slabs automove &lt;0|1&gt;</p>
<ul>
<li>0|1|2 is the indicator on whether to enable the slabs automover or not.</li>
</ul>
<p>The response should always be "OK\r\n"</p>
<ul>
<li>
<p>&lt;0&gt; means to set the thread on standby</p>
</li>
<li>
<p>&lt;1&gt; means to return pages to a global pool when there are more than 2 pages
worth of free chunks in a slab class. Pages are then re-assigned back into
other classes as-needed.</p>
</li>
<li>
<p>&lt;2&gt; is a highly aggressive mode which causes pages to be moved every time
there is an eviction. It is not recommended to run for very long in this
mode unless your access patterns are very well understood.</p>
</li>
</ul>
<h2><a id="user-content-lru-tuning" class="anchor" href="#lru-tuning" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>LRU Tuning</h2>
<p>Memcached supports multiple LRU algorithms, with a few tunables. Effort is
made to have sane defaults however you are able to tune while the daemon is
running.</p>
<p>The traditional model is "flat" mode, which is a single LRU chain per slab
class. The newer (with <code>-o modern</code> or <code>-o lru_maintainer</code>) is segmented into
HOT, WARM, COLD. There is also a TEMP LRU. See doc/new_lru.txt for details.</p>
<p>lru &lt;tune|mode|temp_ttl&gt; </p>
<ul>
<li>
<p>"tune" takes numeric arguments "percent hot", "percent warm",
"max hot age", "max warm age factor". IE: "lru tune 10 25 3600 2.0".
This would cap HOT_LRU at 10% of the cache, or tail is idle longer than
3600s. WARM_LRU is up to 25% of cache, or tail is idle longer than 2x
COLD_LRU.</p>
</li>
<li>
<p>"mode" &lt;flat|segmented&gt;: "flat" is traditional mode. "segmented" uses
HOT|WARM|COLD split. "segmented" mode requires <code>-o lru_maintainer</code> at start
time. If switching from segmented to flat mode, the background thread will
pull items from HOT|WARM into COLD queue.</p>
</li>
<li>
<p>"temp_ttl" : If TTL is less than zero, disable usage of TEMP_LRU. If
zero or above, items set with a TTL lower than this will go into TEMP_LRU
and be unevictable until they naturally expire or are otherwise deleted or
replaced.</p>
</li>
</ul>
<p>The response line could be one of:</p>
<ul>
<li>
<p>"OK" to indicate a successful update of the settings.</p>
</li>
<li>
<p>"ERROR [message]" to indicate a failure or improper arguments.</p>
</li>
</ul>
<h2><a id="user-content-lru_crawler" class="anchor" href="#lru_crawler" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>LRU_Crawler</h2>
<p>NOTE: This command (and related commands) are subject to change as of this
writing.</p>
<p>The LRU Crawler is an optional background thread which will walk from the tail
toward the head of requested slab classes, actively freeing memory for expired
items. This is useful if you have a mix of items with both long and short
TTL's, but aren't accessed very often. This system is not required for normal
usage, and can add small amounts of latency and increase CPU usage.</p>
<p>lru_crawler &lt;enable|disable&gt;</p>
<ul>
<li>Enable or disable the LRU Crawler background thread.</li>
</ul>
<p>The response line could be one of:</p>
<ul>
<li>
<p>"OK" to indicate the crawler has been started or stopped.</p>
</li>
<li>
<p>"ERROR [message]" something went wrong while enabling or disabling.</p>
</li>
</ul>
<p>lru_crawler sleep </p>
<ul>
<li>The number of microseconds to sleep in between each item checked for
expiration. Smaller numbers will obviously impact the system more.
A value of "0" disables the sleep, "1000000" (one second) is the max.</li>
</ul>
<p>The response line could be one of:</p>
<ul>
<li>
<p>"OK"</p>
</li>
<li>
<p>"CLIENT_ERROR [message]" indicating a format or bounds issue.</p>
</li>
</ul>
<p>lru_crawler tocrawl &lt;32u&gt;</p>
<ul>
<li>The maximum number of items to inspect in a slab class per run request. This
allows you to avoid scanning all of very large slabs when it is unlikely to
find items to expire.</li>
</ul>
<p>The response line could be one of:</p>
<ul>
<li>
<p>"OK"</p>
</li>
<li>
<p>"CLIENT_ERROR [message]" indicating a format or bound issue.</p>
</li>
</ul>
<p>lru_crawler crawl &lt;classid,classid,classid|all&gt;</p>
<ul>
<li>
<p>Takes a single, or a list of, numeric classids (ie: 1,3,10). This instructs
the crawler to start at the tail of each of these classids and run to the
head. The crawler cannot be stopped or restarted until it completes the
previous request.</p>
<p>The special keyword "all" instructs it to crawl all slabs with items in
them.</p>
</li>
</ul>
<p>The response line could be one of:</p>
<ul>
<li>
<p>"OK" to indicate successful launch.</p>
</li>
<li>
<p>"BUSY [message]" to indicate the crawler is already processing a request.</p>
</li>
<li>
<p>"BADCLASS [message]" to indicate an invalid class was specified.</p>
</li>
</ul>
<p>lru_crawler metadump &lt;classid,classid,classid|all&gt;</p>
<ul>
<li>
<p>Similar in function to the above "lru_crawler crawl" command, this function
outputs one line for every valid item found in the matching slab classes.
Similar to "cachedump", but does not lock the cache and can return all
items, not just 1MB worth.</p>
<p>Lines are in "key=value key2=value2" format, with value being URI encoded
(ie: %20 for a space).</p>
<p>The exact keys available are subject to change, but will include at least:</p>
<p>"key", "exp" (expiration time), "la", (last access time), "cas",
"fetch" (if item has been fetched before).</p>
</li>
</ul>
<p>The response line could be one of:</p>
<ul>
<li>
<p>"OK" to indicate successful launch.</p>
</li>
<li>
<p>"BUSY [message]" to indicate the crawler is already processing a request.</p>
</li>
<li>
<p>"BADCLASS [message]" to indicate an invalid class was specified.</p>
</li>
</ul>
<h2><a id="user-content-watchers" class="anchor" href="#watchers" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Watchers</h2>
<p>Watchers are a way to connect to memcached and inspect what's going on
internally. This is an evolving feature so new endpoints should show up over
time.</p>
<p>watch &lt;fetchers|mutations|evictions&gt;</p>
<ul>
<li>Turn connection into a watcher. Options can be stacked and are
space-separated. Logs will be sent to the watcher until it disconnects.</li>
</ul>
<p>The response line could be one of:</p>
<ul>
<li>
<p>"OK" to indicate the watcher is ready to send logs.</p>
</li>
<li>
<p>"ERROR [message]" something went wrong while enabling.</p>
</li>
</ul>
<p>The response format is in "key=value key2=value2" format, for easy parsing.
Lines are prepending with "ts=" for a timestamp and "gid=" for a global ID
number of the log line. Given how logs are collected internally they may be
printed out of order. If this is important the GID may be used to put log
lines back in order.</p>
<p>The value of keys (and potentially other things) are "URI encoded". Since most
keys used conform to standard ASCII, this should have no effect. For keys with
less standard or binary characters, "%NN"'s are inserted to represent the
byte, ie: "n%2Cfoo" for "n,foo".</p>
<p>The arguments are:</p>
<ul>
<li>
<p>"fetchers": Currently emits logs every time an item is fetched internally.
This means a "set" command would also emit an item_get log, as it checks for
an item before replacing it. Multigets should also emit multiple lines.</p>
</li>
<li>
<p>"mutations": Currently emits logs when an item is stored in most cases.
Shows errors for most cases when items cannot be stored.</p>
</li>
<li>
<p>"evictions": Shows some information about items as they are evicted from the
cache. Useful in seeing if items being evicted were actually used, and which
keys are getting removed.</p>
</li>
</ul>
<h2><a id="user-content-statistics" class="anchor" href="#statistics" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Statistics</h2>
<p>The command "stats" is used to query the server about statistics it
maintains and other internal data. It has two forms. Without
arguments:</p>
<p>stats\r\n</p>
<p>it causes the server to output general-purpose statistics and
settings, documented below.  In the other form it has some arguments:</p>
<p>stats \r\n</p>
<p>Depending on , various internal data is sent by the server. The
kinds of arguments and the data sent are not documented in this version
of the protocol, and are subject to change for the convenience of
memcache developers.</p>
<h2><a id="user-content-general-purpose-statistics" class="anchor" href="#general-purpose-statistics" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>General-purpose statistics</h2>
<p>Upon receiving the "stats" command without arguments, the server sents
a number of lines which look like this:</p>
<p>STAT  \r\n</p>
<p>The server terminates this list with the line</p>
<p>END\r\n</p>
<p>In each line of statistics,  is the name of this statistic, and
 is the data.  The following is the list of all names sent in
response to the "stats" command, together with the type of the value
sent for this name, and the meaning of the value.</p>
<p>In the type column below, "32u" means a 32-bit unsigned integer, "64u"
means a 64-bit unsigned integer. '32u.32u' means two 32-bit unsigned
integers separated by a colon (treat this as a floating point number).</p>
<p>|-----------------------+---------+-------------------------------------------|
| Name                  | Type    | Meaning                                   |
|-----------------------+---------+-------------------------------------------|
| pid                   | 32u     | Process id of this server process         |
| uptime                | 32u     | Number of secs since the server started   |
| time                  | 32u     | current UNIX time according to the server |
| version               | string  | Version string of this server             |
| pointer_size          | 32      | Default size of pointers on the host OS   |
|                       |         | (generally 32 or 64)                      |
| rusage_user           | 32u.32u | Accumulated user time for this process    |
|                       |         | (seconds:microseconds)                    |
| rusage_system         | 32u.32u | Accumulated system time for this process  |
|                       |         | (seconds:microseconds)                    |
| curr_items            | 64u     | Current number of items stored            |
| total_items           | 64u     | Total number of items stored since        |
|                       |         | the server started                        |
| bytes                 | 64u     | Current number of bytes used              |
|                       |         | to store items                            |
| curr_connections      | 32u     | Number of open connections                |
| total_connections     | 32u     | Total number of connections opened since  |
|                       |         | the server started running                |
| rejected_connections  | 64u     | Conns rejected in maxconns_fast mode      |
| connection_structures | 32u     | Number of connection structures allocated |
|                       |         | by the server                             |
| reserved_fds          | 32u     | Number of misc fds used internally        |
| cmd_get               | 64u     | Cumulative number of retrieval reqs       |
| cmd_set               | 64u     | Cumulative number of storage reqs         |
| cmd_flush             | 64u     | Cumulative number of flush reqs           |
| cmd_touch             | 64u     | Cumulative number of touch reqs           |
| get_hits              | 64u     | Number of keys that have been requested   |
|                       |         | and found present                         |
| get_misses            | 64u     | Number of items that have been requested  |
|                       |         | and not found                             |
| get_expired           | 64u     | Number of items that have been requested  |
|                       |         | but had already expired.                  |
| get_flushed           | 64u     | Number of items that have been requested  |
|                       |         | but have been flushed via flush_all       |
| delete_misses         | 64u     | Number of deletions reqs for missing keys |
| delete_hits           | 64u     | Number of deletion reqs resulting in      |
|                       |         | an item being removed.                    |
| incr_misses           | 64u     | Number of incr reqs against missing keys. |
| incr_hits             | 64u     | Number of successful incr reqs.           |
| decr_misses           | 64u     | Number of decr reqs against missing keys. |
| decr_hits             | 64u     | Number of successful decr reqs.           |
| cas_misses            | 64u     | Number of CAS reqs against missing keys.  |
| cas_hits              | 64u     | Number of successful CAS reqs.            |
| cas_badval            | 64u     | Number of CAS reqs for which a key was    |
|                       |         | found, but the CAS value did not match.   |
| touch_hits            | 64u     | Numer of keys that have been touched with |
|                       |         | a new expiration time                     |
| touch_misses          | 64u     | Numer of items that have been touched and |
|                       |         | not found                                 |
| auth_cmds             | 64u     | Number of authentication commands         |
|                       |         | handled, success or failure.              |
| auth_errors           | 64u     | Number of failed authentications.         |
| idle_kicks            | 64u     | Number of connections closed due to       |
|                       |         | reaching their idle timeout.              |
| evictions             | 64u     | Number of valid items removed from cache  |
|                       |         | to free memory for new items              |
| reclaimed             | 64u     | Number of times an entry was stored using |
|                       |         | memory from an expired entry              |
| bytes_read            | 64u     | Total number of bytes read by this server |
|                       |         | from network                              |
| bytes_written         | 64u     | Total number of bytes sent by this server |
|                       |         | to network                                |
| limit_maxbytes        | size_t  | Number of bytes this server is allowed to |
|                       |         | use for storage.                          |
| accepting_conns       | bool    | Whether or not server is accepting conns  |
| listen_disabled_num   | 64u     | Number of times server has stopped        |
|                       |         | accepting new connections (maxconns).     |
| time_in_listen_disabled_us                                                  |
|                       | 64u     | Number of microseconds in maxconns.       |
| threads               | 32u     | Number of worker threads requested.       |
|                       |         | (see doc/threads.txt)                     |
| conn_yields           | 64u     | Number of times any connection yielded to |
|                       |         | another due to hitting the -R limit.      |
| hash_power_level      | 32u     | Current size multiplier for hash table    |
| hash_bytes            | 64u     | Bytes currently used by hash tables       |
| hash_is_expanding     | bool    | Indicates if the hash table is being      |
|                       |         | grown to a new size                       |
| expired_unfetched     | 64u     | Items pulled from LRU that were never     |
|                       |         | touched by get/incr/append/etc before     |
|                       |         | expiring                                  |
| evicted_unfetched     | 64u     | Items evicted from LRU that were never    |
|                       |         | touched by get/incr/append/etc.           |
| evicted_active        | 64u     | Items evicted from LRU that had been hit  |
|                       |         | recently but did not jump to top of LRU   |
| slab_reassign_running | bool    | If a slab page is being moved             |
| slabs_moved           | 64u     | Total slab pages moved                    |
| crawler_reclaimed     | 64u     | Total items freed by LRU Crawler          |
| crawler_items_checked | 64u     | Total items examined by LRU Crawler       |
| lrutail_reflocked     | 64u     | Times LRU tail was found with active ref. |
|                       |         | Items can be evicted to avoid OOM errors. |
| moves_to_cold         | 64u     | Items moved from HOT/WARM to COLD LRU's   |
| moves_to_warm         | 64u     | Items moved from COLD to WARM LRU         |
| moves_within_lru      | 64u     | Items reshuffled within HOT or WARM LRU's |
| direct_reclaims       | 64u     | Times worker threads had to directly      |
|                       |         | reclaim or evict items.                   |
| lru_crawler_starts    | 64u     | Times an LRU crawler was started          |
| lru_maintainer_juggles                                                      |
|                       | 64u     | Number of times the LRU bg thread woke up |
| slab_global_page_pool | 32u     | Slab pages returned to global pool for    |
|                       |         | reassignment to other slab classes.       |
| slab_reassign_rescues | 64u     | Items rescued from eviction in page move  |
| slab_reassign_evictions_nomem                                               |
|                       | 64u     | Valid items evicted during a page move    |
|                       |         | (due to no free memory in slab)           |
| slab_reassign_chunk_rescues                                                 |
|                       | 64u     | Individual sections of an item rescued    |
|                       |         | during a page move.                       |
| slab_reassign_inline_reclaim                                                |
|                       | 64u     | Internal stat counter for when the page   |
|                       |         | mover clears memory from the chunk        |
|                       |         | freelist when it wasn't expecting to.     |
| slab_reassign_busy_items                                                    |
|                       | 64u     | Items busy during page move, requiring a  |
|                       |         | retry before page can be moved.           |
| log_worker_dropped    | 64u     | Logs a worker never wrote due to full buf |
| log_worker_written    | 64u     | Logs written by a worker, to be picked up |
| log_watcher_skipped   | 64u     | Logs not sent to slow watchers.           |
| log_watcher_sent      | 64u     | Logs written to watchers.                 |
|-----------------------+---------+-------------------------------------------|</p>
<h2><a id="user-content-settings-statistics" class="anchor" href="#settings-statistics" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Settings statistics</h2>
<p>CAVEAT: This section describes statistics which are subject to change in the
future.</p>
<p>The "stats" command with the argument of "settings" returns details of
the settings of the running memcached.  This is primarily made up of
the results of processing commandline options.</p>
<p>Note that these are not guaranteed to return in any specific order and
this list may not be exhaustive.  Otherwise, this returns like any
other stats command.</p>
<p>|-------------------+----------+----------------------------------------------|
| Name              | Type     | Meaning                                      |
|-------------------+----------+----------------------------------------------|
| maxbytes          | size_t   | Maximum number of bytes allowed in the cache |
| maxconns          | 32       | Maximum number of clients allowed.           |
| tcpport           | 32       | TCP listen port.                             |
| udpport           | 32       | UDP listen port.                             |
| inter             | string   | Listen interface.                            |
| verbosity         | 32       | 0 = none, 1 = some, 2 = lots                 |
| oldest            | 32u      | Age of the oldest honored object.            |
| evictions         | on/off   | When off, LRU evictions are disabled.        |
| domain_socket     | string   | Path to the domain socket (if any).          |
| umask             | 32 (oct) | umask for the creation of the domain socket. |
| growth_factor     | float    | Chunk size growth factor.                    |
| chunk_size        | 32       | Minimum space allocated for key+value+flags. |
| num_threads       | 32       | Number of threads (including dispatch).      |
| stat_key_prefix   | char     | Stats prefix separator character.            |
| detail_enabled    | bool     | If yes, stats detail is enabled.             |
| reqs_per_event    | 32       | Max num IO ops processed within an event.    |
| cas_enabled       | bool     | When no, CAS is not enabled for this server. |
| tcp_backlog       | 32       | TCP listen backlog.                          |
| auth_enabled_sasl | yes/no   | SASL auth requested and enabled.             |
| item_size_max     | size_t   | maximum item size                            |
| maxconns_fast     | bool     | If fast disconnects are enabled              |
| hashpower_init    | 32       | Starting size multiplier for hash table      |
| slab_reassign     | bool     | Whether slab page reassignment is allowed    |
| slab_automove     | bool     | Whether slab page automover is enabled       |
| slab_chunk_max    | 32       | Max slab class size (avoid unless necessary) |
| hash_algorithm    | char     | Hash table algorithm in use                  |
| lru_crawler       | bool     | Whether the LRU crawler is enabled           |
| lru_crawler_sleep | 32       | Microseconds to sleep between LRU crawls     |
| lru_crawler_tocrawl                                                         |
|                   | 32u      | Max items to crawl per slab per run          |
| lru_maintainer_thread                                                       |
|                   | bool     | Split LRU mode and background threads        |
| hot_lru_pct       | 32       | Pct of slab memory reserved for HOT LRU      |
| warm_lru_pct      | 32       | Pct of slab memory reserved for WARM LRU     |
| hot_max_age       | 32u      | Max idle age of items in HOT LRU             |
| warm_max_factor   | float    | Set idle age of WARM LRU to COLD age * this  |
| temp_lru          | bool     | If yes, items &lt; temporary_ttl use TEMP_LRU   |
| temporary_ttl     | 32u      | Items with TTL &lt; this are marked  temporary  |
| idle_time         | 0        | Drop connections that are idle this many     |
|                   |          | seconds (0 disables)                         |
| watcher_logbuf_size                                                         |
|                   | 32u      | Size of internal (not socket) write buffer   |
|                   |          | per active watcher connected.                |
| worker_logbuf_size| 32u      | Size of internal per-worker-thread buffer    |
|                   |          | which the background thread reads from.      |
| track_sizes       | bool     | If yes, a "stats sizes" histogram is being   |
|                   |          | dymamically tracked.                         |
| inline_ascii_response                                                       |
|                   | bool     | If yes, stores numbers from VALUE response   |
|                   |          | inside an item, using up to 24 bytes.        |
|                   |          | Small slowdown for ASCII get, faster sets.   |
|-------------------+----------+----------------------------------------------|</p>
<h2><a id="user-content-item-statistics" class="anchor" href="#item-statistics" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Item statistics</h2>
<p>CAVEAT: This section describes statistics which are subject to change in the
future.</p>
<p>The "stats" command with the argument of "items" returns information about
item storage per slab class. The data is returned in the format:</p>
<p>STAT items:: \r\n</p>
<p>The server terminates this list with the line</p>
<p>END\r\n</p>
<p>The slabclass aligns with class ids used by the "stats slabs" command. Where
"stats slabs" describes size and memory usage, "stats items" shows higher
level information.</p>
<p>The following item values are defined as of writing.</p>
<h2><a id="user-content-name-------------------meaning" class="anchor" href="#name-------------------meaning" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Name                   Meaning</h2>
<p>number                 Number of items presently stored in this class. Expired
items are not automatically excluded.
number_hot             Number of items presently stored in the HOT LRU.
number_warm            Number of items presently stored in the WARM LRU.
number_cold            Number of items presently stored in the COLD LRU.
number_temp            Number of items presently stored in the TEMPORARY LRU.
age_hot                Age of the oldest item in HOT LRU.
age_warm               Age of the oldest item in WARM LRU.
age                    Age of the oldest item in the LRU.
evicted                Number of times an item had to be evicted from the LRU
before it expired.
evicted_nonzero        Number of times an item which had an explicit expire
time set had to be evicted from the LRU before it
expired.
evicted_time           Seconds since the last access for the most recent item
evicted from this class. Use this to judge how
recently active your evicted data is.
outofmemory            Number of times the underlying slab class was unable to
store a new item. This means you are running with -M or
an eviction failed.
tailrepairs            Number of times we self-healed a slab with a refcount
leak. If this counter is increasing a lot, please
report your situation to the developers.
reclaimed              Number of times an entry was stored using memory from
an expired entry.
expired_unfetched      Number of expired items reclaimed from the LRU which
were never touched after being set.
evicted_unfetched      Number of valid items evicted from the LRU which were
never touched after being set.
evicted_active         Number of valid items evicted from the LRU which were
recently touched but were evicted before being moved to
the top of the LRU again.
crawler_reclaimed      Number of items freed by the LRU Crawler.
lrutail_reflocked      Number of items found to be refcount locked in the
LRU tail.
moves_to_cold          Number of items moved from HOT or WARM into COLD.
moves_to_warm          Number of items moved from COLD to WARM.
moves_within_lru       Number of times active items were bumped within
HOT or WARM.
direct_reclaims        Number of times worker threads had to directly pull LRU
tails to find memory for a new item.</p>
<p>Note this will only display information about slabs which exist, so an empty
cache will return an empty set.</p>
<h2><a id="user-content-item-size-statistics" class="anchor" href="#item-size-statistics" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Item size statistics</h2>
<p>CAVEAT: This section describes statistics which are subject to change in the
future.</p>
<p>The "stats" command with the argument of "sizes" returns information about the
general size and count of all items stored in the cache.
WARNING: In versions prior to 1.4.27 this command causes the cache server to
lock while it iterates the items. 1.4.27 and greater are safe.</p>
<p>The data is returned in the following format:</p>
<p>STAT  \r\n</p>
<p>The server terminates this list with the line</p>
<p>END\r\n</p>
<p>'size' is an approximate size of the item, within 32 bytes.
'count' is the amount of items that exist within that 32-byte range.</p>
<p>This is essentially a display of all of your items if there was a slab class
for every 32 bytes. You can use this to determine if adjusting the slab growth
factor would save memory overhead. For example: generating more classes in the
lower range could allow items to fit more snugly into their slab classes, if
most of your items are less than 200 bytes in size.</p>
<p>In 1.4.27 and after, this feature must be manually enabled.</p>
<p>A "stats" command with the argument of "sizes_enable" will enable the
histogram at runtime. This has a small overhead to every store or delete
operation. If you don't want to incur this, leave it off.</p>
<p>A "stats" command with the argument of "sizes_disable" will disable the
histogram.</p>
<p>It can also be enabled at starttime with "-o track_sizes"</p>
<p>If disabled, "stats sizes" will return:</p>
<p>STAT sizes_status disabled\r\n</p>
<p>"stats sizes_enable" will return:</p>
<p>STAT sizes_status enabled\r\n</p>
<p>"stats sizes_disable" will return:</p>
<p>STAT sizes_status disabled\r\n</p>
<p>If an error happens, it will return:</p>
<p>STAT sizes_status error\r\n
STAT sizes_error [error_message]\r\n</p>
<p>CAVEAT: If CAS support is disabled, you cannot enable/disable this feature at
runtime.</p>
<h2><a id="user-content-slab-statistics" class="anchor" href="#slab-statistics" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Slab statistics</h2>
<p>CAVEAT: This section describes statistics which are subject to change in the
future.</p>
<p>The "stats" command with the argument of "slabs" returns information about
each of the slabs created by memcached during runtime. This includes per-slab
information along with some totals. The data is returned in the format:</p>
<p>STAT : \r\n
STAT  \r\n</p>
<p>The server terminates this list with the line</p>
<p>END\r\n</p>
<p>|-----------------+----------------------------------------------------------|
| Name            | Meaning                                                  |
|-----------------+----------------------------------------------------------|
| chunk_size      | The amount of space each chunk uses. One item will use   |
|                 | one chunk of the appropriate size.                       |
| chunks_per_page | How many chunks exist within one page. A page by         |
|                 | default is less than or equal to one megabyte in size.   |
|                 | Slabs are allocated by page, then broken into chunks.    |
| total_pages     | Total number of pages allocated to the slab class.       |
| total_chunks    | Total number of chunks allocated to the slab class.      |
| get_hits        | Total number of get requests serviced by this class.     |
| cmd_set         | Total number of set requests storing data in this class. |
| delete_hits     | Total number of successful deletes from this class.      |
| incr_hits       | Total number of incrs modifying this class.              |
| decr_hits       | Total number of decrs modifying this class.              |
| cas_hits        | Total number of CAS commands modifying this class.       |
| cas_badval      | Total number of CAS commands that failed to modify a     |
|                 | value due to a bad CAS id.                               |
| touch_hits      | Total number of touches serviced by this class.          |
| used_chunks     | How many chunks have been allocated to items.            |
| free_chunks     | Chunks not yet allocated to items, or freed via delete.  |
| free_chunks_end | Number of free chunks at the end of the last allocated   |
|                 | page.                                                    |
| mem_requested   | Number of bytes requested to be stored in this slab[*].  |
| active_slabs    | Total number of slab classes allocated.                  |
| total_malloced  | Total amount of memory allocated to slab pages.          |
|-----------------+----------------------------------------------------------|</p>
<ul>
<li>Items are stored in a slab that is the same size or larger than the
item.  mem_requested shows the size of all items within a
slab. (total_chunks * chunk_size) - mem_requested shows memory
wasted in a slab class.  If you see a lot of waste, consider tuning
the slab factor.</li>
</ul>
<h2><a id="user-content-connection-statistics" class="anchor" href="#connection-statistics" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Connection statistics</h2>
<p>The "stats" command with the argument of "conns" returns information
about currently active connections and about sockets that are listening
for new connections. The data is returned in the format:</p>
<p>STAT : \r\n</p>
<p>The server terminates this list with the line</p>
<p>END\r\n</p>
<p>The following "stat" keywords may be present:</p>
<p>|---------------------+------------------------------------------------------|
| Name                | Meaning                                              |
|---------------------+------------------------------------------------------|
| addr                | The address of the remote side. For listening        |
|                     | sockets this is the listen address. Note that some   |
|                     | socket types (such as UNIX-domain) don't have        |
|                     | meaningful remote addresses.                         |
| state               | The current state of the connection. See below.      |
| secs_since_last_cmd | The number of seconds since the most recently        |
|                     | issued command on the connection. This measures      |
|                     | the time since the start of the command, so if       |
|                     | "state" indicates a command is currently executing,  |
|                     | this will be the number of seconds the current       |
|                     | command has been running.                            |
|---------------------+------------------------------------------------------|</p>
<p>The value of the "state" stat may be one of the following:</p>
<p>|----------------+-----------------------------------------------------------|
| Name           | Meaning                                                   |
|----------------+-----------------------------------------------------------|
| conn_closing   | Shutting down the connection.                             |
| conn_listening | Listening for new connections or a new UDP request.       |
| conn_mwrite    | Writing a complex response, e.g., to a "get" command.     |
| conn_new_cmd   | Connection is being prepared to accept a new command.     |
| conn_nread     | Reading extended data, typically for a command such as    |
|                | "set" or "put".                                           |
| conn_parse_cmd | The server has received a command and is in the middle    |
|                | of parsing it or executing it.                            |
| conn_read      | Reading newly-arrived command data.                       |
| conn_swallow   | Discarding excess input, e.g., after an error has         |
|                | occurred.                                                 |
| conn_waiting   | A partial command has been received and the server is     |
|                | waiting for the rest of it to arrive (note the difference |
|                | between this and conn_nread).                             |
| conn_write     | Writing a simple response (anything that doesn't involve  |
|                | sending back multiple lines of response data).            |
|----------------+-----------------------------------------------------------|</p>
<h2><a id="user-content-other-commands" class="anchor" href="#other-commands" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>Other commands</h2>
<p>"flush_all" is a command with an optional numeric argument. It always
succeeds, and the server sends "OK\r\n" in response (unless "noreply"
is given as the last parameter). Its effect is to invalidate all
existing items immediately (by default) or after the expiration
specified.  After invalidation none of the items will be returned in
response to a retrieval command (unless it's stored again under the
same key <em>after</em> flush_all has invalidated the items). flush_all
doesn't actually free all the memory taken up by existing items; that
will happen gradually as new items are stored. The most precise
definition of what flush_all does is the following: it causes all
items whose update time is earlier than the time at which flush_all
was set to be executed to be ignored for retrieval purposes.</p>
<p>The intent of flush_all with a delay, was that in a setting where you
have a pool of memcached servers, and you need to flush all content,
you have the option of not resetting all memcached servers at the
same time (which could e.g. cause a spike in database load with all
clients suddenly needing to recreate content that would otherwise
have been found in the memcached daemon).</p>
<p>The delay option allows you to have them reset in e.g. 10 second
intervals (by passing 0 to the first, 10 to the second, 20 to the
third, etc. etc.).</p>
<p>"cache_memlimit" is a command with a numeric argument. This allows runtime
adjustments of the cache memory limit. It returns "OK\r\n" or an error (unless
"noreply" is given as the last parameter). If the new memory limit is higher
than the old one, the server may start requesting more memory from the OS. If
the limit is lower, and slabs_reassign+automove are enabled, free memory may
be released back to the OS asynchronously.</p>
<p>"version" is a command with no arguments:</p>
<p>version\r\n</p>
<p>In response, the server sends</p>
<p>"VERSION \r\n", where  is the version string for the
server.</p>
<p>"verbosity" is a command with a numeric argument. It always succeeds,
and the server sends "OK\r\n" in response (unless "noreply" is given
as the last parameter). Its effect is to set the verbosity level of
the logging output.</p>
<p>"quit" is a command with no arguments:</p>
<p>quit\r\n</p>
<p>Upon receiving this command, the server closes the
connection. However, the client may also simply close the connection
when it no longer needs it, without issuing this command.</p>
<h2><a id="user-content-udp-protocol" class="anchor" href="#udp-protocol" aria-hidden="true"><svg aria-hidden="true" class="octicon octicon-link" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M4 9h1v1H4c-1.5 0-3-1.69-3-3.5S2.55 3 4 3h4c1.45 0 3 1.69 3 3.5 0 1.41-.91 2.72-2 3.25V8.59c.58-.45 1-1.27 1-2.09C10 5.22 8.98 4 8 4H4c-.98 0-2 1.22-2 2.5S3 9 4 9zm9-3h-1v1h1c1 0 2 1.22 2 2.5S13.98 12 13 12H9c-.98 0-2-1.22-2-2.5 0-.83.42-1.64 1-2.09V6.25c-1.09.53-2 1.84-2 3.25C6 11.31 7.55 13 9 13h4c1.45 0 3-1.69 3-3.5S14.5 6 13 6z"></path></svg></a>UDP protocol</h2>
<p>For very large installations where the number of clients is high enough
that the number of TCP connections causes scaling difficulties, there is
also a UDP-based interface. The UDP interface does not provide guaranteed
delivery, so should only be used for operations that aren't required to
succeed; typically it is used for "get" requests where a missing or
incomplete response can simply be treated as a cache miss.</p>
<p>Each UDP datagram contains a simple frame header, followed by data in the
same format as the TCP protocol described above. In the current
implementation, requests must be contained in a single UDP datagram, but
responses may span several datagrams. (The only common requests that would
span multiple datagrams are huge multi-key "get" requests and "set"
requests, both of which are more suitable to TCP transport for reliability
reasons anyway.)</p>
<p>The frame header is 8 bytes long, as follows (all values are 16-bit integers
in network byte order, high byte first):</p>
<p>0-1 Request ID
2-3 Sequence number
4-5 Total number of datagrams in this message
6-7 Reserved for future use; must be 0</p>
<p>The request ID is supplied by the client. Typically it will be a
monotonically increasing value starting from a random seed, but the client
is free to use whatever request IDs it likes. The server's response will
contain the same ID as the incoming request. The client uses the request ID
to differentiate between responses to outstanding requests if there are
several pending from the same server; any datagrams with an unknown request
ID are probably delayed responses to an earlier request and should be
discarded.</p>
<p>The sequence number ranges from 0 to n-1, where n is the total number of
datagrams in the message. The client should concatenate the payloads of the
datagrams for a given response in sequence number order; the resulting byte
stream will contain a complete response in the same format as the TCP
protocol (including terminating \r\n sequences).</p>
</article>
  </div>

</div>

<button type="button" data-facebox="#jump-to-line" data-facebox-class="linejump" data-hotkey="l" class="d-none">Jump to Line</button>
<div id="jump-to-line" style="display:none">
  <!-- '"` --><!-- </textarea></xmp> --></option></form><form accept-charset="UTF-8" action="" class="js-jump-to-line-form" method="get"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /></div>
    <input class="form-control linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" aria-label="Jump to line" autofocus>
    <button type="submit" class="btn">Go</button>
</form></div>


  </div>
  <div class="modal-backdrop js-touch-events"></div>
</div>

    </div>
  </div>

  </div>

      <div class="container site-footer-container">
  <div class="site-footer" role="contentinfo">
    <ul class="site-footer-links float-right">
        <li><a href="https://github.com/contact" data-ga-click="Footer, go to contact, text:contact">Contact GitHub</a></li>
      <li><a href="https://developer.github.com" data-ga-click="Footer, go to api, text:api">API</a></li>
      <li><a href="https://training.github.com" data-ga-click="Footer, go to training, text:training">Training</a></li>
      <li><a href="https://shop.github.com" data-ga-click="Footer, go to shop, text:shop">Shop</a></li>
        <li><a href="https://github.com/blog" data-ga-click="Footer, go to blog, text:blog">Blog</a></li>
        <li><a href="https://github.com/about" data-ga-click="Footer, go to about, text:about">About</a></li>

    </ul>

    <a href="https://github.com" aria-label="Homepage" class="site-footer-mark" title="GitHub">
      <svg aria-hidden="true" class="octicon octicon-mark-github" height="24" version="1.1" viewBox="0 0 16 16" width="24"><path fill-rule="evenodd" d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0 0 16 8c0-4.42-3.58-8-8-8z"/></svg>
</a>
    <ul class="site-footer-links">
      <li>&copy; 2017 <span title="0.10731s from github-fe-f06f8d5.cp1-iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="https://github.com/site/terms" data-ga-click="Footer, go to terms, text:terms">Terms</a></li>
        <li><a href="https://github.com/site/privacy" data-ga-click="Footer, go to privacy, text:privacy">Privacy</a></li>
        <li><a href="https://github.com/security" data-ga-click="Footer, go to security, text:security">Security</a></li>
        <li><a href="https://status.github.com/" data-ga-click="Footer, go to status, text:status">Status</a></li>
        <li><a href="https://help.github.com" data-ga-click="Footer, go to help, text:help">Help</a></li>
    </ul>
  </div>
</div>



  

  <div id="ajax-error-message" class="ajax-error-message flash flash-error">
    <svg aria-hidden="true" class="octicon octicon-alert" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8.865 1.52c-.18-.31-.51-.5-.87-.5s-.69.19-.87.5L.275 13.5c-.18.31-.18.69 0 1 .19.31.52.5.87.5h13.7c.36 0 .69-.19.86-.5.17-.31.18-.69.01-1L8.865 1.52zM8.995 13h-2v-2h2v2zm0-3h-2V6h2v4z"/></svg>
    <button type="button" class="flash-close js-flash-close js-ajax-error-dismiss" aria-label="Dismiss error">
      <svg aria-hidden="true" class="octicon octicon-x" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
    </button>
    You can't perform that action at this time.
  </div>


    <script crossorigin="anonymous" integrity="sha256-ikMY/+oJoM24IUt2zykmufagztMYoxe+1BnbGSFMaQ0=" src="https://assets-cdn.github.com/assets/compat-8a4318ffea09a0cdb8214b76cf2926b9f6a0ced318a317bed419db19214c690d.js"></script>
    <script crossorigin="anonymous" integrity="sha256-bRCeda2EcbpBUIJybADDX7kpzquXUIJJKDXxHsqMB9k=" src="https://assets-cdn.github.com/assets/frameworks-6d109e75ad8471ba415082726c00c35fb929ceab975082492835f11eca8c07d9.js"></script>
    <script async="async" crossorigin="anonymous" integrity="sha256-Jafjhi94Y/KevPz5fBSZ7I8wWziDw/HZRy8EVu8Fcxo=" src="https://assets-cdn.github.com/assets/github-25a7e3862f7863f29ebcfcf97c1499ec8f305b3883c3f1d9472f0456ef05731a.js"></script>
    
    
    
    
  <div class="js-stale-session-flash stale-session-flash flash flash-warn flash-banner d-none">
    <svg aria-hidden="true" class="octicon octicon-alert" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path fill-rule="evenodd" d="M8.865 1.52c-.18-.31-.51-.5-.87-.5s-.69.19-.87.5L.275 13.5c-.18.31-.18.69 0 1 .19.31.52.5.87.5h13.7c.36 0 .69-.19.86-.5.17-.31.18-.69.01-1L8.865 1.52zM8.995 13h-2v-2h2v2zm0-3h-2V6h2v4z"/></svg>
    <span class="signed-in-tab-flash">You signed in with another tab or window. <a href="">Reload</a> to refresh your session.</span>
    <span class="signed-out-tab-flash">You signed out in another tab or window. <a href="">Reload</a> to refresh your session.</span>
  </div>
  <div class="facebox" id="facebox" style="display:none;">
  <div class="facebox-popup">
    <div class="facebox-content" role="dialog" aria-labelledby="facebox-header" aria-describedby="facebox-description">
    </div>
    <button type="button" class="facebox-close js-facebox-close" aria-label="Close modal">
      <svg aria-hidden="true" class="octicon octicon-x" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path fill-rule="evenodd" d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"/></svg>
    </button>
  </div>
</div>


  </body>
</html>

